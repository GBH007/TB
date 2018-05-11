package main

import (
	"bytes"
	"encoding/json"
	"log"
	"math/rand"
	"os"
)

const (
	GUN     = "gun"
	CARCASE = "carcase"
)

func randomName() string {
	val := "qwertyuiopasdfghjklzxcvbnm0123456789"
	buff := new(bytes.Buffer)
	for i := 0; i < 5; i++ {
		buff.WriteByte(val[rand.Intn(len(val))])
	}
	return buff.String()
}

type Item struct {
	Type     string `json:"type"`
	Name     string `json:"name"`
	MainStat int    `json:"main"`
	AddStat  int    `json:"add"`
	Price    int    `json:"price"`
}
type Tank struct {
	Gun     *Item  `json:"gun"`
	Carcase *Item  `json:"carcase"`
	Name    string `json:"name"`
}
type User struct {
	Name  string  `json:"name"`
	Money int     `json:"money"`
	Wins  int     `json:"wins"`
	Loses int     `json:"loses"`
	Items []*Item `json:"items"`
	Tanks []*Tank `json:"tanks"`
}
type Data struct {
	User  User    `json:"user"`
	Items []*Item `json:"items"`
}
type Controller struct {
	data     *Data
	filename string
}

func NewConroller(filename string) *Controller {
	c := new(Controller)
	c.load(filename)
	c.filename = filename
	return c
}
func (c *Controller) Load() {
	c.load(c.filename)
}
func (c *Controller) load(filename string) error {
	file, err := os.Open(filename)
	if err != nil {
		log.Println(err)
		return err
	}
	decoder := json.NewDecoder(file)
	return decoder.Decode(c.data)
}
func (c *Controller) Save() {
	c.save(c.filename)
}
func (c *Controller) save(filename string) error {
	file, err := os.Create(filename)
	if err != nil {
		log.Println(err)
		return err
	}
	encoder := json.NewEncoder(file)
	return encoder.Encode(c.data)
}
func (c *Controller) generateData() {
	c.data = new(Data)
	c.data.User.Name = "NoName"
	c.data.User.Money = 1000
	c.data.User.Items = make([]*Item, 0)
	c.data.User.Tanks = make([]*Tank, 0)
	for i := 0; i < 100; i++ {
		item := new(Item)
		item.Name = randomName()
		item.MainStat = rand.Intn(100)
		item.AddStat = rand.Intn(100)
		item.Price = rand.Intn(1000)
		if rand.Float64() < 0.5 {
			item.Type = GUN
		} else {
			item.Type = CARCASE
		}
		c.data.Items = append(c.data.Items, item)
	}
}
func main() {
	c := NewConroller("db.json")
	c.generateData()
	c.Save()
}
