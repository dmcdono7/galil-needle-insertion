## Simon's Estimated Velocity Control

Activate it:

```bash
ros2 control switch_controllers --deactivate position_controller --activate velocity_controller
```

Send one command:

```bash
ros2 topic pub -1 /velocity_controller/commands std_msgs/msg/Float64MultiArray "{data: [0.0, 0.0, 0.0, 0.0]}"
```
