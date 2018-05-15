package main

func main() {
	c := NewConroller("db.json")
	c.Load()
	g := NewGUI(c)
	g.Run()
	c.Save()
}
