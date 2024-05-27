#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <std_msgs/UInt32.h>
#include <std_msgs/UInt32MultiArray.h>
#include <tf/transform_listener.h>
#include <fstream>
#include <rosbag/bag.h>


#define SCALE 0.01
#define ACOL 1.0
#define RCOL 0.0
#define GCOL 1.0
#define BCOL 0.0

std::string output_filename = "Coordinates_of_Markers.csv";
std::ofstream outputFile;

std::set<std::string> writtenFrames; // Define a set to keep track of frames that have been written

int sensor_data[4] = {0, 0, 0};

// declare MarkerArray
visualization_msgs::MarkerArray markerMsgs;

// pub pointers
ros::Publisher *pubPtr1;

// callback to manage markers. WIP need to manage angles
void sensorsCallback(const std_msgs::UInt32MultiArray::ConstPtr& msg);
// local function to set the marker color
void setMarkerColor(int pos, int pressure);



int main( int argc, char** argv )
{
  ros::init(argc, argv, "marker_position");
  ros::NodeHandle n;

  ros::Rate r(10);

  ros::Publisher chatter_pub = n.advertise<visualization_msgs::MarkerArray>("vis_marker", 10);



  // initialize the pointers to the pubs
  pubPtr1 = &chatter_pub;

  markerMsgs.markers.resize(4);


  // initialize sensor markers on the first finger
  // initialize first Marker message
  markerMsgs.markers[0].header.frame_id = "link_15_tip";
  markerMsgs.markers[0].ns = "my_namespace";
  markerMsgs.markers[0].id = 0;
  markerMsgs.markers[0].type = visualization_msgs::Marker::CUBE;
  markerMsgs.markers[0].action = visualization_msgs::Marker::ADD;
  markerMsgs.markers[0].pose.position.x = 0.01;
  markerMsgs.markers[0].pose.position.y = 0.0;
  markerMsgs.markers[0].pose.position.z = 0.0;
  markerMsgs.markers[0].pose.orientation.x = 0;
  markerMsgs.markers[0].pose.orientation.y = 0;
  markerMsgs.markers[0].pose.orientation.z = 0;
  markerMsgs.markers[0].pose.orientation.w = 1;
  markerMsgs.markers[0].scale.z = SCALE;
  markerMsgs.markers[0].scale.x = SCALE;
  markerMsgs.markers[0].scale.y = SCALE;
  markerMsgs.markers[0].color.a = ACOL;
  markerMsgs.markers[0].color.r = RCOL;
  markerMsgs.markers[0].color.g = GCOL;
  markerMsgs.markers[0].color.b = BCOL;
  markerMsgs.markers[0].lifetime = ros::Duration();

  // initialize the second Marker message
  markerMsgs.markers[1].header.frame_id = "link_7_tip";
  markerMsgs.markers[1].ns = "my_namespace";
  markerMsgs.markers[1].id = 1;
  markerMsgs.markers[1].type = visualization_msgs::Marker::CUBE;
  markerMsgs.markers[1].action = visualization_msgs::Marker::ADD;
  markerMsgs.markers[1].pose.position.x = 0.01;
  markerMsgs.markers[1].pose.position.y = 0.0;
  markerMsgs.markers[1].pose.position.z = 0.0;
  markerMsgs.markers[1].pose.orientation.x = 0;
  markerMsgs.markers[1].pose.orientation.y = 0;
  markerMsgs.markers[1].pose.orientation.z = 0;
  markerMsgs.markers[1].pose.orientation.w = 1;
  markerMsgs.markers[1].scale.z = SCALE;
  markerMsgs.markers[1].scale.x = SCALE;
  markerMsgs.markers[1].scale.y = SCALE;
  markerMsgs.markers[1].color.a = ACOL;
  markerMsgs.markers[1].color.r = RCOL;
  markerMsgs.markers[1].color.g = GCOL;
  markerMsgs.markers[1].color.b = BCOL;
  markerMsgs.markers[1].lifetime = ros::Duration();

  // initialize the third Marker message
  markerMsgs.markers[2].header.frame_id = "link_11_tip";
  markerMsgs.markers[2].ns = "my_namespace";
  markerMsgs.markers[2].id = 2;
  markerMsgs.markers[2].type = visualization_msgs::Marker::CUBE;
  markerMsgs.markers[2].action = visualization_msgs::Marker::ADD;
  markerMsgs.markers[2].pose.position.x = 0.01;
  markerMsgs.markers[2].pose.position.y = 0.0;
  markerMsgs.markers[2].pose.position.z = 0.0;
  markerMsgs.markers[2].pose.orientation.x = 0;
  markerMsgs.markers[2].pose.orientation.y = 0;
  markerMsgs.markers[2].pose.orientation.z = 0;
  markerMsgs.markers[2].pose.orientation.w = 1;
  markerMsgs.markers[2].scale.z = SCALE;
  markerMsgs.markers[2].scale.x = SCALE;
  markerMsgs.markers[2].scale.y = SCALE;
  markerMsgs.markers[2].color.a = ACOL;
  markerMsgs.markers[2].color.r = RCOL;
  markerMsgs.markers[2].color.g = GCOL;
  markerMsgs.markers[2].color.b = BCOL;
  markerMsgs.markers[2].lifetime = ros::Duration();


  //listener node
  ros::Subscriber sub = n.subscribe("sensor_data", 10, sensorsCallback);


  ros::spin();

  return 0;

}

void sensorsCallback(const std_msgs::UInt32MultiArray::ConstPtr& msg){

  sensor_data[0] = msg->data[0];
  sensor_data[1] = msg->data[1];
  sensor_data[2] = msg->data[2];

  try
  {
    markerMsgs.markers[0].header.stamp = ros::Time(); setMarkerColor(0, sensor_data[0]);
    markerMsgs.markers[1].header.stamp = ros::Time(); setMarkerColor(1, sensor_data[1]);
    markerMsgs.markers[2].header.stamp = ros::Time(); setMarkerColor(2, sensor_data[2]);
    // ROS_INFO("I heard the first sensor: [%i]", sensor_data[0]);
    // ROS_INFO("I heard the second sensor: [%i]", sensor_data[1]);
    
    // publish both messages
    (*pubPtr1).publish(markerMsgs);
    }
  catch(const std::exception& e)
  {
    fprintf(stderr, "Wrong marker array!\n");
  }
}

void setMarkerColor(int pos, int pressure){

  // constrain the value of pressure
  if(pressure < 0)
    pressure = 0;
  else if(pressure > 500)
    pressure = 500;

  // normalize to doubles from 0.0 to 1.0
  float pressureNorm = (float)pressure / 500.0;
  
  // set the color based on pressure
  markerMsgs.markers[pos].color.a = 1.0;
  markerMsgs.markers[pos].color.g = 1.0 - pressureNorm;
  markerMsgs.markers[pos].color.r = 0.0 + pressureNorm;
  markerMsgs.markers[pos].color.b = 0.0;


  tf::TransformListener listener;
    
  tf::StampedTransform transform;

  std::string frame0 = "palm_link"; // Replace with the desired frame name
  std::string frame[] = {"link_15_tip", "link_7_tip", "link_11_tip"};
  std::string frame1 = frame[pos]; 

  // ros::Rate rate(1);
  ros::Time now = ros::Time::now();
  
    if (pressure > 2) {

        // Check if the frame has already been written to the CSV file
        if (writtenFrames.find(frame1) == writtenFrames.end()) {
            outputFile.open(output_filename, std::ios::app);
            if (outputFile.is_open()) {
                try {
                    tf::TransformListener listener;
                    tf::StampedTransform transform;
                    listener.waitForTransform("palm_link", frame1, now, ros::Duration(1));
                    listener.lookupTransform(frame0, frame1, ros::Time(0), transform);
                    double x = transform.getOrigin().x();
                    double y = transform.getOrigin().y();
                    double z = transform.getOrigin().z();

                    outputFile << frame1 << "," << x << "," << y << "," << z << std::endl;

                    // Add the frame to the set to mark it as written
                    writtenFrames.insert(frame1);
                } catch (tf::TransformException& ex) {
                    ROS_ERROR("%s", ex.what());
                }
                outputFile.close();
            } else {
                ROS_ERROR("Failed to open the CSV file.");
            }
        }
    }
}
