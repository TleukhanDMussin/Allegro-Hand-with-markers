#include <iostream>
#include <fstream>
#include <vector>
#include <ros/ros.h>
#include <dynamixel_sdk_examples/SetPosition.h>

double current_x_7_tip, current_y_7_tip, current_z_7_tip, 
        current_x_11_tip, current_y_11_tip, current_z_11_tip, 
        current_x_15_tip, current_y_15_tip, current_z_15_tip,
        prev_x_7_tip, prev_y_7_tip, prev_z_7_tip, 
        prev_x_11_tip, prev_y_11_tip, prev_z_11_tip, 
        prev_x_15_tip, prev_y_15_tip, prev_z_15_tip;

bool isLiftUp = true;
int k = 0;

struct FrameCoordinate {
    std::string frame;
    double x, y, z;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "pose_change");
    ros::NodeHandle nh;

    ros::Publisher position_pub = nh.advertise<dynamixel_sdk_examples::SetPosition>("/set_position", 10);

    std::ifstream inputFile;
    std::string csvFilePath = "/home/rustam/Coordinates_of_Markers.csv";

    std::vector<FrameCoordinate> previousFrameCoordinates;

    while (ros::ok()) {
        inputFile.open(csvFilePath);
        if (!inputFile) {
            ROS_ERROR_STREAM("Failed to open CSV file.");
            return 1;
        }

    std::vector<FrameCoordinate> currentFrameCoordinates;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string token;
        FrameCoordinate frameCoordinate;

        // Read frame name
        if (!std::getline(ss, token, ',')) {
            ROS_ERROR_STREAM("Failed to parse frame name: " << line);
            continue;
        }
        frameCoordinate.frame = token;

        // Read x coordinate
        if (!std::getline(ss, token, ',')) {
            ROS_ERROR_STREAM("Failed to parse x coordinate: " << line);
            continue;
        }
        frameCoordinate.x = std::stod(token);

        // Read y coordinate
        if (!std::getline(ss, token, ',')) {
            ROS_ERROR_STREAM("Failed to parse y coordinate: " << line);
            continue;
        }
        frameCoordinate.y = std::stod(token);

        // Read z coordinate
        if (!std::getline(ss, token)) {
            ROS_ERROR_STREAM("Failed to parse z coordinate: " << line);
            continue;
        }
        frameCoordinate.z = std::stod(token);

        //ROS_INFO("Frame: %s, x: %f, y: %f, z: %f", frameCoordinate.frame.c_str(), frameCoordinate.x, frameCoordinate.y, frameCoordinate.z);
        currentFrameCoordinates.push_back(frameCoordinate);
    }


    inputFile.close();
 

    for (const auto& fc_c : currentFrameCoordinates) {
        if (fc_c.frame == "link_7_tip") {
            current_x_7_tip = fc_c.x;
            current_y_7_tip = fc_c.y;
            current_z_7_tip = fc_c.z;
        } else if (fc_c.frame == "link_11_tip") {
            current_x_11_tip = fc_c.x;
            current_y_11_tip = fc_c.y;
            current_z_11_tip = fc_c.z;
        } else if (fc_c.frame == "link_15_tip"){
            current_x_15_tip = fc_c.x;
            current_y_15_tip = fc_c.y;
            current_z_15_tip = fc_c.z;
        }
    }


    for (const auto& fc : previousFrameCoordinates) {
        if (fc.frame == "link_7_tip") {
            prev_x_7_tip = fc.x;
            prev_y_7_tip = fc.y;
            prev_z_7_tip = fc.z;
        } else if (fc.frame == "link_11_tip") {
            prev_x_11_tip = fc.x;
            prev_y_11_tip = fc.y;
            prev_z_11_tip = fc.z;
        } else if (fc.frame == "link_15_tip"){
            prev_x_15_tip = fc.x;
            prev_y_15_tip = fc.y;
            prev_z_15_tip = fc.z;
        }
    }

    //ROS_INFO("%f", prev_z_7_tip);
    //ROS_INFO("%f", current_z_7_tip);
    // Compare x and z coordinates
    if (current_x_7_tip > 0.115 && current_x_7_tip < 0.117) {
        ROS_INFO("It is a sphere"); //cube
        break;
    } else if (current_x_7_tip > 0.117 && current_x_11_tip > 0.117 && current_x_7_tip < 0.119 && current_x_11_tip < 0.119 
       // && current_z_7_tip > 0.025 && current_z_11_tip > 0.025 && current_z_7_tip < 0.044 && current_z_11_tip < 0.035) ||
        ) {
        dynamixel_sdk_examples::SetPosition msg;
    
        if (k == 0 || k == 1) {
            msg.id = 1; // Control Motor ID 1
            msg.position = -16000; //Set your desired position
            position_pub.publish(msg);
            ROS_INFO("Lifting the platform");
            k++;
        } else if (k > 1 && k <= 3 && current_z_7_tip >= 0.02) {
            msg.id = 2; // Control Motor ID 2
            msg.position = 1837; // Set your desired position here
            position_pub.publish(msg);
            ROS_INFO("Revolving the platfrom");
            k++;
        } 
     

        if ((current_z_7_tip - prev_z_7_tip) >= 0.005 && prev_z_7_tip > 0 && current_z_7_tip > 0.02) {
            ROS_INFO("It is a pyramid"); //cube
            break;
        } else if (((current_z_7_tip - prev_z_7_tip) < 0.002) && prev_z_7_tip > 0 && k > 3){
            ROS_INFO("It is a cylinder");
            //ROS_INFO("%i",k);
            break;
        } else if ((current_z_11_tip - prev_z_11_tip) >= 0.007 && prev_z_11_tip > 0) {
            ROS_INFO("It is a pyramid");
            break;
        } 
    }

    previousFrameCoordinates = currentFrameCoordinates;

    ros::spinOnce();
    ros::Duration(15.0).sleep(); // Sleep for 10 second before the next iteration

    }
    return 0;
}





