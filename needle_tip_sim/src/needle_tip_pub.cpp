#include <needle_tip_sim/needle_tip_sim.hpp>
using namespace std::placeholders;

int main( int argc, char** argv ){

  rclcpp::init( argc, argv );

  std::shared_ptr<NeedleTipSim> publisher = std::make_shared<NeedleTipSim>( "pub" );
  
  while(rclcpp::ok()){

    publisher->publish();
    rclcpp::spin_some(publisher);
  }

  rclcpp::shutdown();
  
  return 0;

}
