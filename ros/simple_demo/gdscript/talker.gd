extends Node2D

# Initialize timeout signal.
signal timeout

# Calls rclcpp::init(0, nullptr) to make sure ROS is started up.
var ros_talker = Talker.new()

var g_timer = null

var count = 1

# Called when the node enters the scene tree fot the first time.
func _ready():
	# Initialize ROS node.
	ros_talker.spin_some()
	
	g_timer = Timer.new()
	add_child(g_timer)
	# Connect the takl signal with the timeout callback.
	g_timer.connect("timeout", self, "_on_Timer_timeout")
	g_timer.set_wait_time(1.0)
	g_timer.set_one_shot(false)
	g_timer.start()
	pass


# Called on timeout signal.
func _on_Timer_timeout():
	print("godot is talking: " + String(count))
	# Talk callback publishes to ROS.
	ros_talker.talk(count)
	count += 1
