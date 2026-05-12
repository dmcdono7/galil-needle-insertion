## Real Velocity Controller

`real_velocity_controller` writes to the `real_velocity` ros2_control interface, which the hardware interface maps to the Galil jog sequence.

If you launched `RSP.launch.py`, it is already active by default.

If need to switch:

```bash
ros2 control switch_controllers --deactivate position_controller --activate real_velocity_controller
```

Send one command:

```bash
ros2 topic pub -1 /real_velocity_controller/commands std_msgs/msg/Float64MultiArray "{data: [0.0, 0.0, 0.0, 0.0]}"
```
