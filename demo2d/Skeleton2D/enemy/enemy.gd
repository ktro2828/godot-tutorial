class_name Enemy
extends KinematicBody2D

var speed = Vector2(120.0, 360.0)
var veclocity = Vector2(120.0, 0.0)

func _ready():
	 $AnimationTree.active = true


func _physics_process(delta):
	if int(delta / 10) % 2 == 0:
		veclocity.x *= -1
		
