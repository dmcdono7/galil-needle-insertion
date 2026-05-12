## Launch Files

### `mariana_view.launch.py`
From Simon
Starts:

- `joint_state_broadcaster` active
- `position_controller` active
- `velocity_controller` inactive
- `real_velocity_controller` inactive
- `sine_real_velocity_controller` inactive

Run it with:

```bash
ros2 launch galil_driver mariana_view.launch.py
```

### `RSP.launch.py`

Starts:

- `joint_state_broadcaster` active
- `real_velocity_controller` active
- `position_controller` inactive
- `velocity_controller` inactive
- `sine_real_velocity_controller` inactive

Run it with:

```bash
ros2 launch galil_driver RSP.launch.py
```
