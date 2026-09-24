int trap(int* height, int heightSize) {

    // Two pointers
    int left = 0;
    int right = heightSize - 1;

    // Maximum heights seen from each side
    int leftMax = 0;
    int rightMax = 0;

    // Total trapped water
    int water = 0;

    while (left < right) {

        // Left side is the limiting side
        if (height[left] <= height[right]) {

            // Found a new maximum on the left
            if (height[left] >= leftMax) {
                leftMax = height[left];
            }

            // Current bar is lower than leftMax
            else {
                water += leftMax - height[left];
            }

            // Move left pointer
            left++;
        }

        // Right side is the limiting side
        else {

            // Found a new maximum on the right
            if (height[right] >= rightMax) {
                rightMax = height[right];
            }

            // Current bar is lower than rightMax
            else {
                water += rightMax - height[right];
            }

            // Move right pointer
            right--;
        }
    }

    return water;
}
