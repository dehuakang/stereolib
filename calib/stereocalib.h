#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "vector"
#include "iostream"

class StereoCalibrator {
	public:
		StereoCalibrator(int num, int bw, int bh, float obj_scale);
		int detectChessboardCorners(cv::Mat& img1, cv::Mat& img2);
		void calibrate(bool update=false);

	private:
		int num_boards;
		int b_width;
		int b_height;
		float ob_scale;
		cv::Size b_size;
		cv::Mat gray1, gray2;
		std::vector<std::vector<cv::Point3f> > objPts;
    	std::vector<std::vector<cv::Point2f> > imgPts1, imgPts2;
    	std::vector<cv::Point2f> corners1, corners2;
    	std::vector<cv::Point3f> obj;
};