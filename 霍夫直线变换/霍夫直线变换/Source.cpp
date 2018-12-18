#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv){
	// ����ֱ�߱任

	// ��ȡͼƬ
	Mat src = imread("D:/OpenCVProject/day1218/����ֱ�߱任/����ֱ�߱任/test.jpg");
	if (!src.data){
		printf("could not load image....");
	}
	//imshow("origin image", src);

	// ��˹ģ����ת�Ҷ�ͼ����Ե���
	Mat gray_src, dst;	
	Canny(src, gray_src, 150, 200);
	cvtColor(gray_src, dst, CV_GRAY2BGR);
	imshow("Canny image", gray_src);

	// ����ֱ�߱任
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