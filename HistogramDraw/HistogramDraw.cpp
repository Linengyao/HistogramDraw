// HistogramDisplay.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<opencv.hpp>
using namespace cv;
int main()
{
	float hisogram_B[256];
	float hisogram_G[256];
	float hisogram_R[256];
	float hisogram[256];
	float pixel[256];
	cv::Mat srcMat = imread("E:\\桌面壁纸\\1.jpg");
	int height = srcMat.rows; //行数
	int width = srcMat.cols;//每行元素数量

	//初始化
	for (int i = 0; i < 256; i++)
	{
		hisogram_B[i] = 0;
		hisogram_G[i] = 0;
		hisogram_B[i] = 0;
	}

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			hisogram_B[srcMat.at<Vec3b>(j, i)[0]]++;
			hisogram_G[srcMat.at<Vec3b>(j, i)[1]]++;
			hisogram_R[srcMat.at<Vec3b>(j, i)[2]]++;

		}//单行处理结束
	}

	//归一化
	for (int i = 0; i < 256; i++)
	{
		hisogram_B[i] = hisogram_B[i] / (height*width);
		hisogram_G[i] = hisogram_G[i] / (height*width);
		hisogram_R[i] = hisogram_R[i] / (height*width);
		//std::cout << hisogram_B[i] << std::endl;
	}

	//绘制直方图
	cv::Mat disMat = imread("E:\\桌面壁纸\\直方图.png");
	int disMat_height = disMat.rows;
	int disMat_width = disMat.cols;
	cv::Point pt1;
	cv::Point pt2;
	pt1.x = 0;
	pt1.y = disMat_height - hisogram_B[0] * disMat_height;
	for (int i = 1; i < 256; i++)
	{
		pt2.x = i;
		pt2.y = disMat_height - hisogram_B[i] * disMat_height/** (height*width)*/;
		line(disMat, pt1, pt2, CV_RGB(255, 0, 0), 1, 8, 0);
		pt1.x = pt2.x;
		pt1.y = pt2.y;
	}

	imshow("disMat", disMat);
	waitKey(0);

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
