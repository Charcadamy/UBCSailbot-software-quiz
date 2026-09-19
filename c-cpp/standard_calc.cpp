#include "stdbool.h"
#include "standard_calc.h"

//Rounds angle to nearest tenths place
float roundToTenthsPlace(float angle){
    //Implementation of rounding without math.h (not sure if math.h is allowed)
    int newAngleInt = (int)(newAngle * 10);
    double newAngleDouble = newAngleInt/10.0;

    //Checks if original angles hundredth place is >= 0.05 i.e. 12.43 - 12.4 = 0.03 < 0.05
    if (newAngle - newAngleDouble >= 0.05)
    {
        newAngleInt = newAngleInt += 1;
        newAngle = newAngleInt / 10.0;
    }
    else
    {
        newAngle = newAngleInt / 10;
    }

    return newAngle;
}

//Returns the same angle but now between 0 and 360
float normalizeAngle (float angle)
{
    if (angle < 0)
    {
        while (angle < 0)
        {
            angle += 360;
        }
    }
    else if (angle > 360)
    {
        while (angle > 360)
        {
            angle -= 360;
        }
    }

    return angle;
}


/**
 * @brief Bounds the provided angle between [-180, 180) degrees.
 *
 * e.g.)
 *      bound_to_180(135) = 135.0
 *      bound_to_180(200) = -160.0
 *
 * @param angle: The input angle in degrees.
 *
 * @return float: The bounded angle in degrees.
 */
float bound_to_180(float angle) {
    if (angle >= 180)
    {
        while(angle >= 180)
        {
            angle = angle - 360;
        }

    }
    else if (angle < 0)
    {
        while(angle < -180)
        {
            angle = angle + 360;
        }
    }

    angle = roundToTenthsPlace(angle);

    return angle;
}
/**
 * @brief Determines whether an angle is between two other angles
 *
 *  e.g.)
 *      is_angle_between(0, 45, 90) = true
 *      is_angle_between(45, 90, 270) = false
 *
 * @param first_angle:  The first bounding angle in degrees.
 * @param middle_angle: The angle in question in degrees.
 * @param second_angle: The second bounding angle in degrees.
 * @return bool: TRUE when `middle_angle` is not in the reflex angle of `first_angle` and `second_angle`, FALSE otherwise
 */
bool is_angle_between(float first_angle, float middle_angle, float second_angle) {

    //First check if angles are positive and between 0 and 360, otherwise convert
    first_angle = normalizeAngle(first_angle);
    middle_angle = normalizeAngle(middle_angle);
    second_angle = normalizeAngle(second_angle);

    //If the angles are the same there can't be an angle between
    if (first_angle == second_angle)
    {
        return false;
    }


    if (first_angle - second_angle > 0)
    {
        if (middle_angle > first_angle || middle_angle < second_angle)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    //Second_angle > first_angle
    else
    {
        if(middle_angle > second_angle || middle_angle < first_angle)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
