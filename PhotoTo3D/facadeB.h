#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include "FacadeSegmentation.h"

class FacadeB {
private:
	static std::pair<int, int> range_NF;
	static std::pair<int, int> range_NC;

protected:
	FacadeB() {}

public:
	static cv::Mat generateFacade(int width, int height, int thickness, int max_NF, int max_NC, const std::vector<float>& params);
	static void decodeParams(float width, float height, int mass_gramamr_id, int max_NF, int max_NC, int num_floors, int num_columns, const std::vector<float>& params, std::vector<float>& decoded_params);
	static cv::Mat generateRandomFacade(int width, int height, int thickness, std::vector<float>& params, float window_displacement = 0, float window_prob = 1);
	static cv::Mat generateFacade(float scale, int width, int height, int thickness, float GH, float FH, float AH, float SW, float TW, float GW, float WT, float WH, float WB, float WS, int WW, float DT, float DH, float DB, float DS, float DW, float window_displacement = 0, float window_prob = 1);

	static int clusterWindowTypes(std::vector<std::vector<fs::WindowPos>>& win_rects);
};
