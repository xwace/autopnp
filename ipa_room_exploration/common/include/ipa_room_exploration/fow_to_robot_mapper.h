#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/Polygon.h>
#include <Eigen/Dense>

#include <ipa_room_exploration/A_star_pathplanner.h>

/*!
 *****************************************************************
 * \file
 *
 * \note
 * Copyright (c) 2016 \n
 * Fraunhofer Institute for Manufacturing Engineering
 * and Automation (IPA) \n\n
 *
 *****************************************************************
 *
 * \note
 * Project name: Care-O-bot
 * \note
 * ROS stack name: autopnp
 * \note
 * ROS package name: ipa_room_exploration
 *
 * \author
 * Author: Florian Jordan
 * \author
 * Supervised by: Richard Bormann
 *
 * \date Date of creation: 11.2016
 *
 * \brief
 *
 *
 *****************************************************************
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer. \n
 * - Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution. \n
 * - Neither the name of the Fraunhofer Institute for Manufacturing
 * Engineering and Automation (IPA) nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission. \n
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License LGPL as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License LGPL for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License LGPL along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************/

#pragma once

// Function that provides the functionality that a given fow path gets mapped to a robot path by using the given parameters.
// To do so simply a vector operation is applied. If the computed robot pose is not in the free space, another accessible
// point is generated by finding it on the radius around the fow middlepoint s.t. the distance to the last robot position
// is minimized.
// Important: the room map needs to be an unsigned char single channel image
void mapPath(const cv::Mat& room_map, std::vector<geometry_msgs::Pose2D>& robot_path,
		const std::vector<geometry_msgs::Pose2D>& fow_path, const Eigen::Matrix<float, 2, 1>& robot_to_fow_vector,
		const double map_resolution, const cv::Point2d map_origin, const cv::Point& starting_point);
