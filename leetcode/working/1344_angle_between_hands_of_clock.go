// 1344. Angle Betwenn Hands of a Clock
// https://leetcode.com/problems/angle-between-hands-of-a-clock/
package main

func angleClock(hour int, minutes int) float64 {
	// Normalize hour to 12-hour format
	hour = hour % 12

	// Calculate angle of hour hand
	// Each hour is 30 degrees (360/12)
	// Each minute adds 0.5 degrees to the hour hand (30/60)
	// 60minutes is 1hr, where 1hr is 30 degrees
	// minute_degrees = (given_minutes * 30 ) / 60
	// which means add the value of minutes*30/60 to the hour angle
	hourAngle := float64(hour*30) + float64(minutes)*0.5

	// Calculate angle of minute hand
	// Each minute is 6 degrees (360/60)
	minuteAngle := float64(minutes) * 6

	// Find the absolute difference between the angles
	angle := math.Abs(hourAngle - minuteAngle)

	// Return the smaller angle between the two hands
	// (either the direct angle or 360 - angle)
	if angle > 180 {
		return 360 - angle
	}
	return angle
}
