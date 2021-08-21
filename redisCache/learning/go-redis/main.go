package main

import (
	"database/sql"
	"encoding/json"
	"fmt"
	"log"
	"net/http"

	_ "github.com/mattn/go-sqlite3"
)

type SQLite struct {
	DB *sql.DB
}

func (s *SQLite) GetUsers() []User {
	return []User{}
}

// global db pointer for now
// it can be pushed into handlers using dependency injection pattern
var db *sql.DB

type User struct {
	Uname      string `json:"uname"`
	First_name string `json:"first_name"`
	Last_name  string `json:"last_name"`
	Age        int    `json:"age"`
}

type Tweet struct {
	Content   string `json:"content"`
	CreatedAt int    `json:"created_at"`
	UserId    int    `json:"user_id"`
}

type Follow struct {
	CreatedAt  int `json:"created_at"`
	FollowerId int `json:"follower_id"`
	FolloweeId int `json:"followee_id"`
}

type GetFollow struct {
	UserId int `json:"user_id"`
}

func home(w http.ResponseWriter, r *http.Request) {
	if r.URL.Path != "/" {
		http.NotFound(w, r)
		return
	}
	w.Write([]byte("This is Home Page!"))
}

func addNewUser(w http.ResponseWriter, r *http.Request) {
	if r.Method != "POST" {
		w.Header().Set("Allow", "POST")
		w.WriteHeader(405)
		w.Write([]byte("Method not allowed"))
		return
	}

	decoder := json.NewDecoder(r.Body)
	user := User{}
	decoder.Decode(&user)

	// TODO is user_name already exists from cache or from sqlit

	if db != nil {
		stmt, e := db.Prepare("INSERT INTO users(UNAME,FIRST_NAME,LAST_NAME,AGE) values (?,?,?,?)")
		stmt.Exec(user.Uname, user.First_name, user.Last_name, user.Age)
		fmt.Println("error = ", e)
	}

	fmt.Println(user)
	w.Write([]byte("addNewUser API !"))
}

func addTweet(w http.ResponseWriter, r *http.Request) {
	if r.Method != "POST" {
		w.Header().Set("Allow", "POST")
		w.WriteHeader(405)
		w.Write([]byte("Method not allowed"))
		return
	}
	decoder := json.NewDecoder(r.Body)
	tweet := Tweet{}
	decoder.Decode(&tweet)

	if db != nil {
		stmt, e := db.Prepare("INSERT INTO tweets(CONTENT,CREATED_AT,USER_ID) values (?,?,?)")
		stmt.Exec(tweet.Content, tweet.CreatedAt, tweet.UserId)
		fmt.Println("error = ", e)
	}

	fmt.Println(tweet)
	w.Write([]byte("addTweet API !"))
}

func follow(w http.ResponseWriter, r *http.Request) {
	if r.Method != "POST" {
		w.Header().Set("Allow", "POST")
		w.WriteHeader(405)
		w.Write([]byte("Method not allowed"))
		return
	}
	decoder := json.NewDecoder(r.Body)
	follow := Follow{}
	decoder.Decode(&follow)

	if db != nil {
		stmt, e := db.Prepare("INSERT INTO follower(CREATED_AT,FOLLOWER_ID,FOLLOWEE_ID) values (?,?,?)")
		stmt.Exec(follow.CreatedAt, follow.FollowerId, follow.FolloweeId)
		fmt.Println("error = ", e)
	}

	fmt.Println(follow)
	w.Write([]byte("follow API !"))
}

func getFollowers(w http.ResponseWriter, r *http.Request) {
	if r.Method != "GET" {
		w.Header().Set("Allow", "GET")
		w.WriteHeader(405)
		w.Write([]byte("Method not allowed"))
		return
	}

	decoder := json.NewDecoder(r.Body)
	getFollow := GetFollow{}
	decoder.Decode(&getFollow)

	rows, err := db.Query(`select * from users
		where id in (
			select id from follower
			where followee_id = ?
		);`, getFollow.UserId)

	if err != nil {
		log.Fatal(err)
	}
	defer rows.Close()

	users := []User{}
	for rows.Next() {
		user := User{}
		var id int
		err := rows.Scan(&id, &user.Uname, &user.First_name, &user.Last_name, &user.Age)
		if err != nil {
			log.Fatal(err)
		}
		users = append(users, user)
	}
	log.Println(users)
	w.Header().Set("Content-Type", "application/json")
	encoder := json.NewEncoder(w)
	encoder.Encode(users)
}

func getUser(w http.ResponseWriter, r *http.Request) {
	if r.Method != "GET" {
		w.WriteHeader(405)
		w.Write([]byte("Method not allowed"))
		return
	}
	w.Write([]byte("getUser API !"))
}

func main() {
	dbptr, _ := sql.Open("sqlite3", "./twitter.db")
	db = dbptr

	stmt1, _ := db.Prepare(`
		CREATE TABLE IF NOT EXISTS
		users (
			ID	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
			UNAME  			TEXT  	NOT NULL,
			FIRST_NAME     	TEXT   	NOT NULL,
			LAST_NAME      TEXT    NOT NULL,
			AGE				INTEGER NOT NULL
		);
	`)

	stmt1.Exec()

	stmt2, _ := db.Prepare(`
		CREATE TABLE IF NOT EXISTS
		tweets (
			ID	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
			CONTENT        TEXT    NOT NULL,
			CREATED_AT     INT     NOT NULL,
			USER_ID        INT     NOT NULL,
			FOREIGN KEY (USER_ID) REFERENCES USERS(ID)
		);
	`)

	stmt2.Exec()

	stmt3, _ := db.Prepare(`
		CREATE TABLE IF NOT EXISTS
		follower (
			ID	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
			CREATED_AT     INT     NOT NULL,
			FOLLOWER_ID    INT     NOT NULL,
			FOLLOWEE_ID    INT     NOT NULL,
			FOREIGN KEY (FOLLOWER_ID) REFERENCES USERS(ID),
			FOREIGN KEY (FOLLOWEE_ID) REFERENCES USERS(ID)
		);
	`)

	stmt3.Exec()

	mux := http.NewServeMux()

	mux.HandleFunc("/", home)
	mux.HandleFunc("/adduser", addNewUser)
	mux.HandleFunc("/addTweet", addTweet)
	mux.HandleFunc("/follow", follow)
	mux.HandleFunc("/getuser", getUser)
	mux.HandleFunc("/getfollowers", getFollowers)

	log.Println("Started server on:4123")
	err := http.ListenAndServe(":4123", mux)
	log.Println(err)
}
