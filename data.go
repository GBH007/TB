package main

import (
	"bytes"
	"math/rand"
)

const (
	GUN     = "gun"
	CARCASE = "carcase"
	VERSION = "v0.1"
)

func selectItemByType(items map[int]*Item, t string) map[int]*Item {
	res := make(map[int]*Item)
	for i, item := range items {
		if item.Type == t {
			res[i] = item
		}
	}
	return res
}
func randomName() string {
	val := "qwertyuiopasdfghjklzxcvbnm0123456789"
	buff := new(bytes.Buffer)
	for i := 0; i < 5; i++ {
		buff.WriteByte(val[rand.Intn(len(val))])
	}
	return buff.String()
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type Item struct {
	Type     string `json:"type"`
	Name     string `json:"name"`
	MainStat int    `json:"main"`
	Price    int    `json:"price"`
}
type Tank struct {
	Gun     *Item  `json:"gun"`
	Carcase *Item  `json:"carcase"`
	Name    string `json:"name"`
}
type User struct {
	Money      int           `json:"money"`
	Wins       int           `json:"wins"`
	Loses      int           `json:"loses"`
	Items      map[int]*Item `json:"items"`
	Tanks      map[int]*Tank `json:"tanks"`
	LastItemId int           `json:"last_item_id"`
	LastTankId int           `json:"last_tank_id"`
}

func (u *User) AddItem(item *Item) {
	u.Items[u.LastItemId] = item
	u.LastItemId++
}
func (u *User) DelItem(index int) {
	delete(u.Items, index)
}
func (u *User) AddTank(tank *Tank) {
	u.Tanks[u.LastTankId] = tank
	u.LastTankId++
}
func (u *User) DelTank(index int) {
	delete(u.Tanks, index)
}

type Data struct {
	User       *User         `json:"user"`
	Items      map[int]*Item `json:"items"`
	LastItemId int           `json:"last_item_id"`
}

func (d *Data) AddItem(item *Item) {
	d.Items[d.LastItemId] = item
	d.LastItemId++
}
func (d *Data) DelItem(index int) {
	delete(d.Items, index)
}
