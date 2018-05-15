package main

type StepLog struct {
	Damage      int
	RandomCoeff int
	TargetName  string
}
type BattleLog struct {
	Steps []*StepLog
	Win   bool
}

func (bl *BattleLog) AddStep(step *StepLog) {
	bl.Steps = append(bl.Steps, step)
}
