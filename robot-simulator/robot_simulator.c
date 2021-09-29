#include "robot_simulator.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
  robot_direction_t dir = direction;
  robot_position_t pos;
  pos.x = x;
  pos.y = y;

  robot_status_t status;
  status.direction = dir;
  status.position = pos;

  return status;
}

void robot_move(robot_status_t *robot, const char *commands) {
  printf("Commands: %s\n", commands);

  for (size_t command = 0; command < strlen(commands); command++) {

    switch (commands[command]) {
    case 'A': {
      switch (robot->direction) {
      case NORTH:
        ++robot->position.y;
        break;

      case EAST:
        ++robot->position.x;
        break;

      case SOUTH:
        --robot->position.y;
        break;

      case WEST:
        --robot->position.x;
        break;

      default:
        break;
      }
    }

    break;

    case 'R':
      switch (robot->direction) {
      case NORTH:
        robot->direction = EAST;
        break;

      case EAST:
        robot->direction = SOUTH;
        break;

      case SOUTH:
        robot->direction = WEST;
        break;

      case WEST:
        robot->direction = NORTH;
        break;

      default:
        break;
      }
      break;

    case 'L':
      switch (robot->direction) {
      case NORTH:
        robot->direction = WEST;
        break;

      case WEST:
        robot->direction = SOUTH;
        break;

      case SOUTH:
        robot->direction = EAST;
        break;

      case EAST:
        robot->direction = NORTH;
        break;

      default:
        break;
      }
      break;
    }
  }
}
