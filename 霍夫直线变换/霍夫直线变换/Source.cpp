#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv){
	// 霍夫直线变换

	// 读取图片
	Mat src = imread("D:/OpenCVProject/day1218/霍夫直线变换/霍夫直线变换/test.jpg");
	if (!src.data){
		printf("could not load image....");
	}
	//imshow("origin image", src);

	// 高斯模糊，转灰度图，边缘检测
	Mat gray_src, dst;	
	Canny(src, gray_src, 150, 200);
	cvtColor(gray_src, dst, CV_GRAY2BGR);
	imshow("Canny image", gray_src);

	// 霍夫直线变换
	vector<Vec4f>plines;
	HoughLinesP(gray_src, plines, 1, CV_PI / 180.0, 10, 0, 5);
	Scalar color = Scalar(0, 255, 255);
	for (int i = 0; i < plines.size(); i++)
	{
		Vec4f hline = plines[i];
		line(dst, Point(hline[0], hline[1]), Point(hline[2], hline[3]), color, 3, LINE_AA);
	}
	imshow("final image", dst);










	waitKey(0);
	return 0;
}