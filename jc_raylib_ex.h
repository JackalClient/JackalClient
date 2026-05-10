#pragma once

/*
 *   ____    ______   __    __  ____    __   __   ______  ____    __  __  ____    ______   _____   __  __  ____
 *  /\  _`\ /\  _  \ /\ \  /\ \/\  _`\ /\ \ /\ \ /\__  _\/\  _`\ /\ \/\ \/\  _`\ /\__  _\ /\  __`\/\ \/\ \/\  _`\
 *  \ \ \L\ \ \ \L\ \\ `\`\\/'/\ \ \L\_\ `\`\/'/'\/_/\ \/\ \ \L\_\ \ `\\ \ \,\L\_\/_/\ \/ \ \ \/\ \ \ `\\ \ \,\L\_\
 *   \ \ ,  /\ \  __ \`\ `\ /'  \ \  _\L`\/ > <     \ \ \ \ \  _\L\ \ , ` \/_\__ \  \ \ \  \ \ \ \ \ \ , ` \/_\__ \
 *    \ \ \\ \\ \ \/\ \ `\ \ \   \ \ \L\ \ \/'/\`\   \ \ \ \ \ \L\ \ \ \`\ \/\ \L\ \ \_\ \__\ \ \_\ \ \ \`\ \/\ \L\ \
 *     \ \_\ \_\ \_\ \_\  \ \_\   \ \____/ /\_\\ \_\  \ \_\ \ \____/\ \_\ \_\ `\____\/\_____\\ \_____\ \_\ \_\ `\____\
 *      \/_/\/ /\/_/\/_/   \/_/    \/___/  \/_/ \/_/   \/_/  \/___/  \/_/\/_/\/_____/\/_____/ \/_____/\/_/\/_/\/_____/
 *
 *
 */
#include "raylib/raymath.h"
#include <cmath>
#define clrequ(c1, c2)	(ColorToInt(c1)==ColorToInt(c2))

RLColor g_back_color{ BLACK };
RLColor g_fore_color{ WHITE };
RLColor g_fill_color{ BLUE };
int g_fs{ 32 };
int g_linewidth{ 1 };
float g_spacing{ 0.0f };
char g_fontname[80]{ 0 };
RLImage* g_pimg_buffer{ nullptr };

inline bool is_run()
{
	return !RLWindowShouldClose();
}
inline HWND GetRaylibWindow(void)
{
	//return FindWindowA("GLFW30", nullptr);
	return (HWND)RLGetWindowHandle();
}
RLVector2 MakeVector2(double x, double y)
{
	return RLVector2{ float(x), float(y) };
}
RLRectangle MakeRectangle(float left, float top, float right, float bottom)
{
	return RLRectangle{ left, top, right - left, bottom - top };
}
RLRectangle MakeRectangle0(float left, float top, float width, float height)
{
	return RLRectangle{ left, top, width, height };
}
void settarget(RLImage* pimg)
{
	g_pimg_buffer = pimg;
}
inline void rectangle(int left, int top, int right, int bottom)
{
	RLDrawRectangleLines(left, top, right - left, bottom - top, g_fore_color);
}
inline void bar(int left, int top, int right, int bottom)
{
	RLDrawRectangle(left, top, right - left, bottom - top, g_fill_color);
}
inline void ege_fillrect(int left, int top, int width, int height)
{
	RLDrawRectangle(left, top, width, height, g_fill_color);
}
inline void rectangle_stroke(int left, int top, int right, int bottom)
{
	RLDrawRectangle(left, top, right - left, bottom - top, g_fill_color);
	RLDrawRectangleLines(left, top, right - left, bottom - top, g_fore_color);
}

inline void setlinewidth(int w)
{
	g_linewidth = w;
}
void setcolor(RLColor color)
{
	g_fore_color = color;
}
inline RLColor getcolor()
{
	return g_fore_color;
}
void setbkcolor(RLColor bkcolor)
{
	g_back_color = bkcolor;
}
inline RLColor getbkcolor()
{
	return g_back_color;
}
void setfillcolor(RLColor fillcolor)
{
	g_fill_color = fillcolor;
}
inline RLColor getfillcolor()
{
	return g_fill_color;
}
void setfont(int fs, int width, const char* fontName)
{
	g_fs = fs;
	strncpy(g_fontname, fontName, 80);
}
int getwidth(RLImage* pimg)
{
	if (!pimg)
		return g.uix;
	return pimg->width;
}
int getheight(RLImage* pimg)
{
	if (!pimg)
		return g.uiy;
	return pimg->height;
}
inline void api_sleep(int ms)
{
	RLWaitTime(ms / 1000.0);
}

///////////////////////////////////////////////////////////
//                  Color 颜色系列                        //
///////////////////////////////////////////////////////////

#define LIGHTRED RAYRGB(0xFC, 0x54, 0x54)
//橙黄系列
#define IVORY RAYRGB(255,255,240)	//极淡黄 
#define CORNSILK RAYRGB(255,248,220)	//淡黄 
//#define GOLD RAYRGB(255,215,0)
//#define ORANGE RAYRGB(255,165,0)

//绿色系列
//#define DARKGREEN RAYRGB(0,100,0)

//蓝系列
#define POWDERBLUE RAYRGB(176,224,230)
#define AQUA RAYRGB(0,0xFC,0xFC)
#define ROYALBLUE RAYRGB(65,105,225)
#define STEELBLUE RAYRGB(70,130,180)
#define CADETBLUE RAYRGB(95,158,160)
#define LIGHTBLUE1 RAYRGB(191,239,255)
#define LIGHTCYAN1 RAYRGB(224,255,255)
#define TURQUOISE RAYRGB(64,224,208)	//青色 
#define CYAN RAYRGB(0,0xA8,0xA8)

//粉紫系列
//#define PINK RAYRGB(255,105,180)
#define LIGHTPINK RAYRGB(255,182,193)
//#define MAROON RAYRGB(176,48,96)
//#define VIOLET RAYRGB(238,130,238)
#define PLUM RAYRGB(221,160,221)
//#define PURPLE RAYRGB(160,32,240)

//黑白系列
#define GRAY_11 RAYRGB(28,28,28)
#define DIMGRAY RAYRGB(105,105,105)
#define SLATEGRAY RAYRGB(112,128,144)	//略带蓝色

#define LIKE_GRAYSCALE_THRESHOLD 10.0

bool LikeGrayscaleColor(RLColor color)
{
	double avg = (color.r + color.g + color.b) / 3.0;
	if (abs(color.r - avg) + abs(color.g - avg) + abs(color.b - avg) > LIKE_GRAYSCALE_THRESHOLD)
		return false;
	return true;
}

RLColor WMAPI Color16ToRGB(UINT u16Clr)
{
	switch (u16Clr)
	{
	case 0: {
		return RAYRGB(0, 0, 0);		//黑 
		break;
	}
	case 1: {
		return RAYRGB(0, 0, 128);	//深蓝 
		break;
	}
	case 2: {
		return RAYRGB(0, 128, 0);	//草绿 
		break;
	}
	case 3: {
		return RAYRGB(0, 128, 128);	//青色 
		break;
	}
	case 4: {
		return RAYRGB(128, 0, 0);	//Dark Red
		break;
	}
	case 5: {
		return RAYRGB(128, 0, 128);	//Dark Magenta
		break;
	}
	case 6: {
		return RAYRGB(128, 128, 0);	//Brown
		break;
	}
	case 7: {
		return RAYRGB(192, 192, 192);	//浅灰 
		break;
	}
	case 8: {
		return RAYRGB(128, 128, 128);	//深灰 
		break;
	}
	case 9: {
		return RAYRGB(0, 0, 255);	//海蓝 
		break;
	}
	case 10: {
		return RAYRGB(0, 255, 0);	//淡绿 
		break;
	}
	case 11: {
		return RAYRGB(0, 255, 255);	//淡蓝 
		break;
	}
	case 12: {
		return RAYRGB(255, 0, 0);	//血红 
		break;
	}
	case 13: {
		return RAYRGB(255, 0, 255);	//Magenta 紫色 
		break;
	}
	case 14: {
		return RAYRGB(255, 255, 0);	//淡黄 
		break;
	}
	case 15: {
		return RAYRGB(255, 255, 255);	//白 
		break;
	}
	default: {
		return RAYRGB(0, 0, 0);
		break;
	}
	}
}
inline RLColor WMAPI RateColor(RLColor orig, float rate)
{
	return RAYRGBA(Clamp(int(RAYGET_R(orig) * rate), 0, 255),
		Clamp(int(RAYGET_G(orig) * rate), 0, 255),
		Clamp(int(RAYGET_B(orig) * rate), 0, 255),
		orig.a);
}

RLColor StepColor(RLColor startColor, RLColor endColor, double rate) {
	// 获取起始颜色分量
	auto startR = RAYGET_R(startColor);
	auto startG = RAYGET_G(startColor);
	auto startB = RAYGET_B(startColor);
	auto startA = RAYGET_A(startColor);

	// 获取结束颜色分量
	auto endR = RAYGET_R(endColor);
	auto endG = RAYGET_G(endColor);
	auto endB = RAYGET_B(endColor);
	auto endA = RAYGET_A(endColor);

	// 计算过渡颜色分量
	auto newR = (startR + (endR - startR) * rate);
	auto newG = (startG + (endG - startG) * rate);
	auto newB = (startB + (endB - startB) * rate);
	auto newA = (startA + (endA - startA) * rate);

	// 构造过渡颜色
	RLColor resultColor = RAYRGBA(newR, newG, newB, newA);
	return resultColor;
}

RLColor WMAPI StepAddColor(RLColor startColor, RLColor endColor, int value) {

	auto startR = RAYGET_R(startColor);
	auto startG = RAYGET_G(startColor);
	auto startB = RAYGET_B(startColor);
	auto startA = RAYGET_A(startColor);
	
	auto endR = RAYGET_R(endColor);
	auto endG = RAYGET_G(endColor);
	auto endB = RAYGET_B(endColor);
	auto endA = RAYGET_A(endColor);

	auto newR = (startR + ((endR - startR) > 0 ? value : (-value)));
	auto newG = (startG + ((endG - startG) > 0 ? value : (-value)));
	auto newB = (startB + ((endB - startB) > 0 ? value : (-value)));
	auto newA = (startA + ((endA - startA) > 0 ? value : (-value)));

	if (abs(newR - endR) <= .5 * value)	newR = endR;
	if (abs(newG - endG) <= .5 * value)	newG = endG;
	if (abs(newB - endB) <= .5 * value)	newB = endB;
	if (abs(newA - endA) <= .5 * value)	newA = endA;

	RLColor resultColor = RAYRGBA(newR, newG, newB, newA);
	return resultColor;
}

#define WVC_AMP 12
#define WVC_OMEGA 13.0
#define WVC_PHASE0 0
clock_t lastWvBeg = 0;
inline RLColor WaveColor(RLColor originClr, float phi = 0.0f) {	//originClr将成为最大值
	//闪烁的颜色 赋予游戏文字灵性
	short val = WVC_AMP * sin(WVC_OMEGA * ((clock() - lastWvBeg) / 1000.0) + WVC_PHASE0 + phi) - WVC_AMP * 2;
	short r = RAYGET_R(originClr) + val, g = RAYGET_G(originClr) + val, b = RAYGET_B(originClr) + val;
	auto a = RAYGET_A(originClr);
	ClampA<short>(r, 2, 255);
	ClampA<short>(g, 2, 255);
	ClampA<short>(b, 2, 255);
	return RAYRGBA(r, g, b, a);
}

RLColor InvertedColor(RLColor color)
{
	return RAYRGBA(255 - RAYGET_R(color), 255 - RAYGET_G(color), 255 - RAYGET_B(color), RAYGET_A(color));
}

// 主函数：返回随时间变化的彩虹色
RLColor RainbowColor(float phase0 /*= 0.0f*/, float speed /*= 30.0f*/) {
	// 假设时间按秒计算，这里使用系统时间或其他适当的时间源
	double timeInSeconds = clock() / 1000.0;

	// 初始相位
	double initial_phase = phase0 * 360.0;

	// 色相按时间变化，加上初始相位
	double hue = fmod(timeInSeconds * speed + initial_phase, 360.0);  // 假设每秒变化30度

	// 饱和度和亮度保持不变
	double saturation = 1.0;
	double value = 1.0;

	// 将HSV颜色转换为RGB并返回
	return RLColorFromHSV(hue, saturation, value);
}

// 定义一个颜色映射，存储每个字符串对应的颜色
static unordered_map<string, RLColor> colorMap;

// 函数：生成饱和度最高的随机颜色
RLColor GetHighSaturationColor() {
	// 使用 C++ 随机数引擎生成随机的 RGB 分量
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 255);

	// 随机选择一个颜色分量作为最大值，其余两个分量设置为较小值
	int r = dis(gen);
	int g = dis(gen);
	int b = dis(gen);

	if (r >= g && r >= b) {
		g = dis(gen) / 2;  // 降低 g 的值
		b = dis(gen) / 2;  // 降低 b 的值
	}
	else if (g >= r && g >= b) {
		r = dis(gen) / 2;  // 降低 r 的值
		b = dis(gen) / 2;  // 降低 b 的值
	}
	else {
		r = dis(gen) / 2;  // 降低 r 的值
		g = dis(gen) / 2;  // 降低 g 的值
	}

	// 返回最终的 RGB 颜色值
	return RAYRGB(r, g, b);
}

// 函数：根据字符串返回对应颜色
RLColor GetStringColor(string_view s) {
	// 查找字符串是否已经有对应的颜色
	auto it = colorMap.find(string(s));
	if (it != colorMap.end()) {
		// 如果已存在，直接返回存储的颜色
		return it->second;
	}
	else {
		// 否则生成一个新的颜色并存储
		RLColor newColor = GetHighSaturationColor();
		colorMap[string(s)] = newColor;
		return newColor;
	}
}
// 生成与 base 颜色相近的颜色（通过 HSL 的简单变换或者直接 RGB 微扰）
RLColor SlightVariant(const RLColor& base, double jitter /*= 0.06*/) {
	// 假设 Color 存在 r,g,b,a 成员 [0..255]
	RLColor out = base;
	auto perturb = [&](unsigned char c)->unsigned char {
		int delta = (int)round((RandomRangeDouble(-jitter, jitter)) * 255.0);
		int val = int(c) + delta;
		if (val < 0) val = 0; if (val > 255) val = 255; return (unsigned char)val;
	};
	out.r = perturb(base.r);
	out.g = perturb(base.g);
	out.b = perturb(base.b);
	// alpha keep as base.a
	return out;
}

// 模板函数：计算正弦颜色并将其映射到指定范围
RLColor SinColor(RLColor colorA, RLColor colorB, clock_t periodTime = 2000L, float phase0 = 0.0f) {
	//// 获取当前时间
	//clock_t currentTime = clock();

	//// 计算周期内的时间
	//double normalizedTime = static_cast<double>(currentTime % periodTime) / periodTime;

	//// 计算正弦值并将其映射到[0, 1]
	//double sinValue = 0.5 * (1.0 + sin(2.0 * PI * normalizedTime));

	//// 计算颜色分量的差值
	//Color deltaColor;
	//deltaColor.r = colorB.r - colorA.r;
	//deltaColor.g = colorB.g - colorA.g;
	//deltaColor.b = colorB.b - colorA.b;
	//deltaColor.a = colorB.a - colorA.a;

	//// 计算正弦颜色
	//Color sinColor;
	//sinColor.r = colorA.r + static_cast<unsigned char>(deltaColor.r * sinValue);
	//sinColor.g = colorA.g + static_cast<unsigned char>(deltaColor.g * sinValue);
	//sinColor.b = colorA.b + static_cast<unsigned char>(deltaColor.b * sinValue);
	//sinColor.a = colorA.a + static_cast<unsigned char>(deltaColor.a * sinValue);

	//return sinColor;

	return StepColor(colorA, colorB, SinValue(0.0f, 1.0f, periodTime, phase0));
}
RLColor TripleColor(RLColor colorA, RLColor colorB, RLColor colorC, clock_t periodTime = 2000L, float phase0 = 0.0f) {
	clock_t now = clock();
	float currentPhase = static_cast<float>(now % periodTime) / periodTime;
	currentPhase += phase0;
	currentPhase = fmod(currentPhase, 1.0f);
	if (currentPhase < 0) currentPhase += 1.0f;

	float stagePhase = currentPhase * 3.0f;
	int stage = static_cast<int>(stagePhase);
	if (stage < 0) stage += 3; // 处理负相位
	stage %= 3;
	float t = stagePhase - stage;

	// 计算平滑过渡参数
	const float angle = t * static_cast<float>(PI) - static_cast<float>(PI / 2);
	const float t_sin = (sin(angle) + 1.0f) / 2.0f;

	// 确定当前渐变色对
	RLColor start, end;
	switch (stage) {
	case 0:  start = colorA; end = colorB; break;
	case 1:  start = colorB; end = colorC; break;
	default: start = colorC; end = colorA; break;
	}

	// 计算插值颜色
	return {
		static_cast<unsigned char>(start.r * (1 - t_sin) + end.r * t_sin),
		static_cast<unsigned char>(start.g * (1 - t_sin) + end.g * t_sin),
		static_cast<unsigned char>(start.b * (1 - t_sin) + end.b * t_sin),
		static_cast<unsigned char>(start.a * (1 - t_sin) + end.a * t_sin)
	};
}

RLColor LighterColor(RLColor color)
{
	return StepColor(color, RAYRGBA(255, 255, 255, color.a), 0.5);
}
RLColor DoLighterColor(RLColor color, bool enabled)
{
	return enabled ? StepColor(color, RAYRGBA(255, 255, 255, color.a), 0.5) : color;
}
RLColor DarkerColor(RLColor color)
{
	return StepColor(color, RAYRGBA(0, 0, 0, color.a), 0.5);
}
RLColor DoDarkerColor(RLColor color, bool enabled)
{
	return enabled ? StepColor(color, RAYRGBA(0, 0, 0, color.a), 0.5) : color;
}
RLColor ColorAlpha2(RLColor color, float alpha)
{
	return RLColorAlpha(color, Lerp(0.0f, color.a / 255.0f, alpha));
}
RLColor RBExchangedColor(RLColor color) {
	return RLColor(color.b, color.g, color.r, color.a);
}

RLColor FadeInOutColor(RLColor bodyColor, clock_t deltaTime, clock_t totalTime, clock_t inTime, clock_t outTime, RLColor endColor = BLACK)
{
	if (deltaTime >= inTime && deltaTime <= totalTime - outTime)
		return bodyColor;
	if (deltaTime >= totalTime || deltaTime <= 0L)
		return endColor;
	if (deltaTime <= inTime)
		return StepColor(endColor, bodyColor, deltaTime / double(inTime));
	return StepColor(bodyColor, endColor, (deltaTime - (totalTime - outTime)) / double(outTime));
}
COLORREF WinColor(RLColor rayColor) {
	return RGB(rayColor.r, rayColor.g, rayColor.b);
}
RLColor RayColor(COLORREF winColor) {
	return RAYRGB(GetRValue(winColor), GetGValue(winColor), GetBValue(winColor));
}
RLColor RayColor(ImVec4 imColor) {
	return RAYRGB(imColor.x * 255, imColor.y * 255, imColor.z * 255);
}
ImVec4 ImGuiColor(RLColor rayColor) {
	return ImVec4(rayColor.r / 255.0f, rayColor.g / 255.0f, rayColor.b / 255.0f, rayColor.a / 255.0f);
}
ImVec4 ImGuiColor(int r, int g, int b, int a = 255) {
	return ImVec4(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
}
ImVec4 ImGuiColor(COLORREF winColor) {
	return ImGuiColor(RayColor(winColor));
}

ImVec4 RainbowColorImGui(float phase0 = 0.0f, float speed = 30.0f) {
	return ImGuiColor(RainbowColor(phase0, speed));
}

// 将UTF-8 codepoints转换为ImGui所需的GlyphRanges格式
ImVector<ImWchar> ConvertToGlyphRanges(const vector<int>& codepoints) {
	ImVector<ImWchar> glyph_ranges;
	for (int cp : codepoints) {
		// 将每个codepoint添加到glyph_ranges中
		glyph_ranges.push_back(static_cast<ImWchar>(cp));
	}
	// 添加结束符
	glyph_ranges.push_back(0);
	return glyph_ranges;
}

//Color GetColorInYear(float phase0 = 0.0f, float alpha = 1.0f) {
//	// 计算颜色
//	Color color;
//	constexpr double frequency = 1.0 / 365.0; // 控制颜色变化的速度，可以根据需要调整
//
//	// 根据相位调整起始点
//	int adjday = static_cast<int>(phase0 * 365);
//	color.r = static_cast<unsigned char>((1 + sin(frequency * (adjday + g.yday))) * 127.5);
//	color.g = static_cast<unsigned char>((1 + sin(frequency * (adjday + g.yday + 2))) * 127.5);
//	color.b = static_cast<unsigned char>((1 + sin(frequency * (adjday + g.yday + 4))) * 127.5);
//	color.a = 255 * alpha;
//	return color;
//}


///////////////////////////////////////////////////////////
//                  Display 显示系列                      //
///////////////////////////////////////////////////////////

inline void cls(RLImage* pimg = nullptr, RLColor color = BLANK)
{
	if (!pimg)
	{
		RLBeginDrawing();
		RLClearBackground(color);
	}
	else
		RLImageClearBackground(pimg, color);
}

int textwidth(const char* str, int fs/* = 0*/, float spacing /*= g_spacing*/)
{
	if (!g.init_hwnd) return fs;
	if (!str) return 0;
	if (0 == fs || fs < 0 || !std::isfinite((double)fs))
		fs = g_fs > 0 ? g_fs : 12;
	if (0.0f == spacing || !std::isfinite(spacing))
		spacing = g_spacing;
	RLFont font = g.font;
	if (!RLIsFontValid(font))
		font = RLGetFontDefault();
	// glyphs 为空时（例如从后台线程调用，字体尚未加载到当前上下文）
	// 回退到字符数估算，避免 RLMeasureTextEx 访问空指针崩溃（读取 0x00000010）
	if (font.glyphs == nullptr)
		return (int)(strlen(str) * fs * 0.6f);
	return RLMeasureTextEx(font, str, fs, spacing).x;
	//return TextLength(str) * (g_fs + g_spacing);
}
inline int textheight(...)
{
	return g_fs;
	//return MeasureTextEx(g.font, str, g_fs, g_spacing).y;
}

string FoldString3(
	const string& s,
	int maxWidth,
	bool ellipse = true,
	bool middleEllipse = false
) {
	if (maxWidth <= 0) return "";

	const string fullEllipsis = "...";

	// ==== 计算省略号宽度 ====
	int ellipsisFullWidth = textwidth(fullEllipsis.c_str(), g_fs, g_spacing);

	string ellipsis;
	int ellipsisWidth = 0;

	if (ellipse) {
		if (maxWidth >= ellipsisFullWidth) {
			ellipsis = fullEllipsis;
			ellipsisWidth = ellipsisFullWidth;
		}
		else {
			// 截断省略号
			string tmp;
			for (char c : fullEllipsis) {
				string t(1, c);
				int w = textwidth(t.c_str(), g_fs, g_spacing);
				if (w > maxWidth - textwidth(tmp.c_str(), g_fs, g_spacing))
					break;
				tmp += c;
			}
			ellipsis = tmp;
			ellipsisWidth = textwidth(tmp.c_str(), g_fs, g_spacing);
		}
	}

	if (ellipsisWidth >= maxWidth)
		return ellipsis;

	// ==== 切字符（UTF-8 安全） ====
	vector<string> cut;
	try {
		cut = CutCharacters(s);
	}
	catch (...) {
		string tmp = s;
		ANSI2UTF8(tmp);
		cut = CutCharacters(tmp);
	}

	int n = (int)cut.size();
	if (n == 0) return "";

	// ==== 前缀宽度表 ====
	vector<int> prefixWidth(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		prefixWidth[i + 1] =
			prefixWidth[i] + textwidth(cut[i].c_str(), g_fs, g_spacing);
	}

	// ==== 不使用省略号 ====
	if (!ellipse) {
		int L = 0, R = n;
		while (L < R) {
			int mid = (L + R + 1) / 2;
			if (prefixWidth[mid] <= maxWidth) L = mid;
			else R = mid - 1;
		}

		string res;
		for (int i = 0; i < L; ++i) res += cut[i];
		return res;
	}

	int bodyMaxWidth = maxWidth - ellipsisWidth;

	// ======================================================
	// 末尾省略（原行为）
	// ======================================================
	if (!middleEllipse) {
		int L = 0, R = n;
		while (L < R) {
			int mid = (L + R + 1) / 2;
			if (prefixWidth[mid] <= bodyMaxWidth) L = mid;
			else R = mid - 1;
		}

		string res;
		for (int i = 0; i < L; ++i) res += cut[i];

		if (L == n) return res;
		return res + ellipsis;
	}

	// ======================================================
	// ★ 中间省略（新增）
	// ======================================================

	int bestLeft = 0;
	int bestRight = 0;

	// 双指针：左右对称向内收
	int l = 0;
	int r = n;

	while (l <= r) {
		int leftWidth = prefixWidth[l];
		int rightWidth =
			prefixWidth[n] - prefixWidth[r];

		if (leftWidth + rightWidth <= bodyMaxWidth) {
			bestLeft = l;
			bestRight = n - r;
			++l;
			--r;
		}
		else {
			break;
		}
	}

	// 构造结果
	string res;

	for (int i = 0; i < bestLeft; ++i)
		res += cut[i];

	res += ellipsis;

	for (int i = n - bestRight; i < n; ++i)
		res += cut[i];

	return res;
}


RLRectangle ZoomingRect(const RLRectangle& rt, double rate)
{
	float midx = rt.x + rt.width / 2.0f;
	float midy = rt.y + rt.height / 2.0f;
	RLRectangle rt2;
	rt2.width = EaseOutCubic(rate) * rt.width;
	rt2.height = EaseOutCubic(rate) * rt.height;
	rt2.x = midx - rt2.width / 2.0f;
	rt2.y = midy - rt2.height / 2.0f;
	return rt2;
}

void CheckExtraFontChars(const string& s)
{
	if (g.thr_main_id != 0 && GetCurrentThreadId() != g.thr_main_id) {
		return; // Font reload/unload must only happen on main render thread
	}
	string mode = GET_COMBOBOX(g.config.gui_config["Font Reload Policy (for Non-ASCII)"]).get<string>();
	if (mode.find("Deny") != string::npos)
		return;		// 拒绝检查重载字体
	long autoUnloadMaxCount = 12000L;
	if (g.config.config_config.contains("Auto Unload Front Extra Font Chars Max Count")) {
		try {
			autoUnloadMaxCount = max<long>(0L, g.config.config_config["Auto Unload Front Extra Font Chars Max Count"].get<long>());
		}
		catch (...) {}
	}
	// Hard safety cap: prevents oversized glyph atlas from long-running lyric sessions.
	if (autoUnloadMaxCount > 6000L) {
		autoUnloadMaxCount = 6000L;
	}
	int garbage;
	//<!> UTF-8
	bool changed{ false };
	list<int> codePoints;

	for (size_t i = 0; i < s.length(); ++i)
	{
		int n = 1;
		if ((unsigned char)(s[i]) < 0x80)
			n = 1;
		else if (((unsigned char)(s[i]) & 0xE0) == 0xC0)
			n = 2;
		else if (((unsigned char)(s[i]) & 0xF0) == 0xE0)
			n = 3;
		else if (((unsigned char)(s[i]) & 0xF8) == 0xF0)
			n = 4;
		
		//if ((unsigned char)(s[i]) >= 0xE0 && (unsigned char)(s[i]) <= 0xEF)
		//if ((unsigned char)(s[i]) > 0x7F && (unsigned char)(s[i]) < upper_bounds[j])
		if (n > 1)
		{

			
			int codePoint = RLGetCodepoint(s.substr(i, n).c_str(), &garbage);
			if (codePoint <= 0 || codePoint > 0x10FFFF || (codePoint >= 0xD800 && codePoint <= 0xDFFF)) {
				i += n - 1;
				continue;
			}

			bool notfound = (g.extra_chars_codepoints_set.find(codePoint) == g.extra_chars_codepoints_set.end());

			if (notfound) {
				for (int j : g.extra_chars_codepoints_buffer)
					if (j == codePoint)
					{
						notfound = false;
						break;
					}
			}

			if (notfound)
			{
				//g.notify.WarningMessage("AddExtraChar, codepoint = " + str(codePoint) + " utf8str = " + str(CodepointToUTF8(codePoint, &garbage)));

				changed = true;

				//DebugLog("ADD CODEPOINT="+str(codePoint)+" CHAR="+s.substr(i, 3)+ '\n');
				g.extra_chars_codepoints_buffer.push_back(codePoint);
			}

			// 由于中文字符占用3个字节，因此增加索引i的值
			i += n - 1;
			continue;
		}
	}

	if (changed || !g.extra_chars_codepoints_buffer.empty())
	{
		if (g.config.gui_config.contains("Font Reload Cooldown (ms)") && clock() - g.lastFontReload < g.config.gui_config["Font Reload Cooldown (ms)"].get<long>()) {
			return;
		}

		while (!g.extra_chars_codepoints_buffer.empty()) {
			int cp = g.extra_chars_codepoints_buffer.front();
			g.extra_chars_codepoints_buffer.pop_front();
			if (cp <= 0 || cp > 0x10FFFF || (cp >= 0xD800 && cp <= 0xDFFF)) {
				continue;
			}
			g.AddExtraChar(cp, RLCodepointToUTF8(cp, &garbage));
		}

		if (autoUnloadMaxCount > 0L && (long)g.extra_chars_codepoints.size() > autoUnloadMaxCount) {
			size_t removeCount = g.extra_chars_codepoints.size() - (size_t)autoUnloadMaxCount;
			if (removeCount > 0 && removeCount <= g.extra_chars_codepoints.size()) {
				g.extra_chars_codepoints.erase(g.extra_chars_codepoints.begin(), g.extra_chars_codepoints.begin() + removeCount);
				g.extra_chars_codepoints_set.clear();
				g.extra_chars_codepoints_set.insert(g.extra_chars_codepoints.begin(), g.extra_chars_codepoints.end());
				g.extra_chars.clear();
				for (int cp : g.extra_chars_codepoints) {
					g.extra_chars += RLCodepointToUTF8(cp, &garbage);
				}
			}
		}
			

		g.lastFontReload = clock();
		// Suppress transient font glyph warnings during hot-reload to avoid console spam.
		RLSetTraceLogLevel(RL_E_LOG_ERROR);
		ReloadFont();
		RLSetTraceLogLevel(g.log_level);
	}
}

// 已废弃
#define DPIF(coord) (AllowHighDPI() ? ((coord) / g.screen_scale) : (coord))

void outtextxy(int x, int y, const char* text)
{
	CheckExtraFontChars(text);
	RLDrawTextEx(g.font, text, MakeVector2((x), (y)), g_fs, g_spacing, g_fore_color);
}
int xyprintf(int x, int y, const char* szFormat, ...)
{
	char buffer[1024]{ 0 };

	va_list va;
	va_start(va, szFormat);
	int ret = vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	//DrawText(buffer, x, y, g_fs, g_fore_color);

	CheckExtraFontChars(buffer);
	RLDrawTextEx(g.font, buffer, MakeVector2((x), (y)), g_fs, g_spacing, g_fore_color);
	return ret;
}
void glowprint(
	int x,
	int y,
	RLColor glowColor,
	int radius,
	const char* text
)
{
	CheckExtraFontChars(text);

	static const RLVector2 dirs[] = {
	{ 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 },
	{ 1, 1 }, { -1, 1 }, { 1, -1 }, { -1, -1 }
	};

	for (int r = radius; r > 0; r--)
	{
		float t = (float)r / radius;
		float falloff = (1.0f - t);
		falloff *= falloff;

		RLColor c = glowColor;
		c.a = (unsigned char)(glowColor.a * falloff);

		for (auto& d : dirs)
		{
			RLDrawTextEx(
				g.font,
				text,
				{ x + d.x * r, y + d.y * r },
				g_fs,
				g_spacing,
				c
			);
		}
	}

	RLDrawTextEx(
		g.font,
		text,
		MakeVector2(x, y),
		g_fs,
		g_spacing,
		g_fore_color
	);
}

void glowprintf(
	int x,
	int y,
	RLColor glowColor,
	int radius,
	const char* szFormat,
	...
)
{
	char buffer[1024];

	va_list va;
	va_start(va, szFormat);
	vsnprintf(buffer, sizeof(buffer), szFormat, va);
	va_end(va);

	glowprint(x, y, glowColor, radius, buffer);
}

void glowprintf(
	int x,
	int y,
	float glowOpacity,
	int radius,
	const char* szFormat,
	...
)
{
	char buffer[1024];

	va_list va;
	va_start(va, szFormat);
	vsnprintf(buffer, sizeof(buffer), szFormat, va);
	va_end(va);

	RLColor glow = g_fore_color;
	glow.a = (unsigned char)(g_fore_color.a * glowOpacity);

	glowprint(x, y, glow, radius, buffer);
}
void glowprint_rotate(
	int x,
	int y,
	float rotation,
	RLColor glowColor,
	int radius,
	const char* text
)
{
	CheckExtraFontChars(text);

	static const RLVector2 dirs[] = {
		{ 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 },
		{ 1, 1 }, { -1, 1 }, { 1, -1 }, { -1, -1 }
	};

	int w = textwidth(text, g_fs, g_spacing);
	RLVector2 origin = { w / 2.0f, g_fs / 2.0f };

	// 预计算旋转
	float rad = rotation * DEG2RAD;
	float cs = cosf(rad);
	float sn = sinf(rad);

	for (int r = radius; r > 0; r--)
	{
		float t = (float)r / radius;
		float falloff = (1.0f - t);
		falloff *= falloff;

		RLColor c = glowColor;
		c.a = (unsigned char)(glowColor.a * falloff);

		for (auto& d : dirs)
		{
			// 先算偏移
			float ox = d.x * r;
			float oy = d.y * r;

			// 再旋转偏移
			RLVector2 offset = {
				ox * cs - oy * sn,
				ox * sn + oy * cs
			};

			RLDrawTextPro(
				g.font,
				text,
				{ x + offset.x, y + offset.y },
				origin,
				rotation,
				g_fs,
				g_spacing,
				c
			);
		}
	}

	// 正常文字
	RLDrawTextPro(
		g.font,
		text,
		MakeVector2(x, y),
		origin,
		rotation,
		g_fs,
		g_spacing,
		g_fore_color
	);
}
int glowprintf_rotate(
	int x,
	int y,
	float rotation,
	RLColor glowColor,
	int radius,
	const char* szFormat,
	...
)
{
	char buffer[1024]{};

	va_list va;
	va_start(va, szFormat);
	int ret = vsnprintf(buffer, sizeof(buffer), szFormat, va);
	va_end(va);

	glowprint_rotate(x, y, rotation, glowColor, radius, buffer);
	return ret;
}
int glowprintf_rotate(
	int x,
	int y,
	float rotation,
	float glowOpacity,
	int radius,
	const char* szFormat,
	...
)
{
	char buffer[1024]{};

	va_list va;
	va_start(va, szFormat);
	int ret = vsnprintf(buffer, sizeof(buffer), szFormat, va);
	va_end(va);

	RLColor glow = g_fore_color;
	glow.a = (unsigned char)(g_fore_color.a * glowOpacity);

	glowprint_rotate(x, y, rotation, glow, radius, buffer);
	return ret;
}
int flowprintf(int x, int y, bool flow, float phase0, const char* szFormat, ...) {
	char buffer[1024]{ 0 };

	va_list va;
	va_start(va, szFormat);
	int ret = vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	//DrawText(buffer, x, y, g_fs, g_fore_color);

	CheckExtraFontChars(buffer);
	if (ModuleOn(PowerSaving) && MODBOOL("Power Saving", "Weak Rendering")) {
		flow = false;
	}
	if (flow) {
		g.flow.SetDynamicColor(1000 * MODLONG("Shader", "Flow Text Theme Period (s)"), phase0);
		g.flow.RLDrawText(buffer, x, y, g_fs, g_fore_color);
	}
	else {
		RLDrawTextEx(g.font, buffer, MakeVector2((x), (y)), g_fs, g_spacing, g_fore_color);
	}
	return ret;
}
int flowprintf_rotate(int x, int y, bool flow, float phase0, float rotation, const char* szFormat, ...) {
	char buffer[1024]{ 0 };

	va_list va;
	va_start(va, szFormat);
	int ret = vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	//DrawText(buffer, x, y, g_fs, g_fore_color);

	CheckExtraFontChars(buffer);
	if (ModuleOn(PowerSaving) && MODBOOL("Power Saving", "Weak Rendering")) {
		flow = false;
	}
	if (flow) {
		g.flow.SetDynamicColor(1000 * MODLONG("Shader", "Flow Text Theme Period (s)"), phase0);
		g.flow.RLDrawText(buffer, x, y, g_fs, rotation, g_fore_color);
	}
	else {
		int w = textwidth(buffer, g_fs, g_spacing);
		RLDrawTextPro(g.font, buffer, MakeVector2((x), (y)), {w / 2.0f, g_fs / 2.0f}, rotation, g_fs, g_spacing, g_fore_color);
	}
	return ret;
}

//void scrollouttextxy(int x, int y, int w, const char* text)
//{
//	constexpr int space_cnt = 6;
//
//	string s0{ text };
//	string s{ text };
//	if (MeasureTextEx(g.font, s.c_str(), g_fs, g_spacing).x > w)
//	{
//		int i = (clock() / 200L);
//		/*int max_cnt = w / g_fs * 2;*/
//		int back_cnt = s0.length() - i % s0.length();
//		s = s0.substr(i % s.length(), back_cnt);
//
//		int len2 = MeasureTextEx(g.font, s.c_str(), g_fs, g_spacing).x
//			+ g_fs / 2 * space_cnt;
//		if (w > len2)
//		{
//			//int fore_cnt = (w - len2) / g_fs;
//			s += string(space_cnt, ' ');
//			//s += s0.substr(0, fore_cnt);
//			s += s0;	//为了省事，去使用ScissorMode裁剪掉出去的部分 (掉出去的部分<1个字符)
//		}
//
//	}
//	CheckExtraFontChars(s);
//	DrawTextEx(g.font, s.c_str(), MakeVector2((x), (y)), g_fs, g_spacing, g_fore_color);
//}
void scrollouttextxy(int x, int y, int w, const char* text)
{
	constexpr int space_cnt = 6;
	static double offset = 0.0;      // 单调增加，不循环

	std::string s0(text);

	float textWidth = RLMeasureTextEx(g.font, s0.c_str(), g_fs, g_spacing).x;

	if (textWidth <= w)
	{
		CheckExtraFontChars(s0);
		RLDrawTextEx(g.font, s0.c_str(), RLVector2{ (float)x, (float)y }, g_fs, g_spacing, g_fore_color);
		return;
	}

	std::string spaces(space_cnt, ' ');
	std::string segment = s0 + spaces;

	float segWidth = RLMeasureTextEx(g.font, segment.c_str(), g_fs, g_spacing).x;

	//float speed = 60.0f; // 像素/秒，可调整

	//offset += speed * GetFrameTime();   // 永远增加
	// speed 是 “每秒滚动文本宽度的百分比”
	float speed_norm = 0.018f * g.config.gui_config["Scroll Text Speed"].get<float>();  // 每秒移动 x% 的 segment 长度，可调
	offset += segWidth * speed_norm * RLGetFrameTime();

	// 计算平铺起点
	float fx = fmod((float)offset, segWidth);
	if (fx < 0) fx += segWidth;

	// 第一个片段绘制位置
	float startX = x - fx;

	CheckExtraFontChars(segment);

	// 画至少 3 份，保证完全覆盖裁剪区域
	for (int i = 0; i < 3; i++)
	{
		float drawX = startX + i * segWidth;
		RLDrawTextEx(g.font, segment.c_str(),
			RLVector2{ drawX, (float)y },
			g_fs, g_spacing, g_fore_color);
	}
}

int scrollprintf(int x, int y, int w, const char* szFormat, ...)
{	//横向滚动
	char buffer[1024]{ 0 };

	va_list va;
	va_start(va, szFormat);
	int ret = vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);

	scrollouttextxy(x, y, w, buffer);

	return ret;
}

int xyprintf(RLImage* pimg, int x, int y, const char* szFormat, ...)
{

	char buffer[1024]{ 0 };

	va_list va;
	va_start(va, szFormat);
	int ret = vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	//DrawText(buffer, x, y, g_fs, g_fore_color);

	CheckExtraFontChars(buffer);
	//DrawTextEx(g.font, buffer, MakeVector2(x, y), g_fs, g_spacing, g_fore_color);
	RLImageDrawTextEx(pimg, g.font, buffer, MakeVector2(x, y), g_fs, g_spacing, g_fore_color);
	return ret;
}

short KnowItsLen(u_char c) {
	short ret = 0;
	if (c > 0x7f)	ret = 2;
	else			ret = 1;
	return ret;
}

void WMAPI midprinty(const string& strText, int y, int left = 0, int right = g.uix)
{
	xyprintf((left + right) / 2.0 - textwidth(strText.c_str()) / 2.0, y, "%s", strText.c_str());
}

void WMAPI scrollmidprinty(const string& strText, int y, int w, int left = 0, int right = g.uix)
{
	scrollouttextxy((left + right) / 2.0 - min(w, textwidth(strText.c_str())) / 2.0, y, w, strText.c_str());
}
#define _OFFSET_X 0
void WMAPI midprinty_shadow(const string& strText, int y, int midx = g.uix / 2, int shadow_distance = 1)
{
	RLColor color = getcolor();
	setcolor(GetTextShadowColor(color));

	int fy = textheight('1');	//font height
	int sx = textwidth(strText.c_str(), fy);
	int x = midx - sx / 2 + _OFFSET_X;
	xyprintf(x + shadow_distance, y + shadow_distance, "%s", strText.c_str());

	setcolor(color);
	midprinty(strText, y, midx - 20, midx + 20);
}
void WMAPI scrollmidprinty_shadow(const string& strText, int y, int w, int midx = g.uix / 2, int shadow_distance = 1)
{
	RLColor color = getcolor();
	setcolor(GetTextShadowColor(color));

	int fy = textheight('1');	//font height
	int sx = textwidth(strText.c_str());
	int x = midx - sx / 2 + _OFFSET_X;
	scrollouttextxy(x + shadow_distance, y + shadow_distance, w, strText.c_str());

	setcolor(color);
	scrollmidprinty(strText, y, w, midx, midx);
}

void WMAPI midprinty_stroke(const string& strText, int y, int midx = g.uix / 2, int stroke_distance = 1)
{
	RLColor color = getcolor();
	setcolor(GetTextShadowColor(color));

	int fy = textheight('1');	//font height
	int sx = textwidth(strText.c_str());
	int x = midx - sx / 2 + _OFFSET_X;
	xyprintf(x - stroke_distance, y - stroke_distance, "%s", strText.c_str());
	xyprintf(x - stroke_distance, y + stroke_distance, "%s", strText.c_str());
	xyprintf(x + stroke_distance, y - stroke_distance, "%s", strText.c_str());
	xyprintf(x + stroke_distance, y + stroke_distance, "%s", strText.c_str());

	setcolor(color);
	midprinty(strText, y, midx, midx);
}
void WMAPI scrollmidprinty_stroke(const string& strText, int y, int w, int midx = g.uix / 2, int stroke_distance = 1)
{
	RLColor color = getcolor();
	setcolor(RAYRGBA(1, 1, 1, color.a));

	int fy = textheight('1');	//font height
	int sx = textwidth(strText.c_str());
	int x = midx - sx / 2 + _OFFSET_X;
	scrollouttextxy(x - stroke_distance, y - stroke_distance, w, strText.c_str());
	scrollouttextxy(x - stroke_distance, y + stroke_distance, w, strText.c_str());
	scrollouttextxy(x + stroke_distance, y - stroke_distance, w, strText.c_str());
	scrollouttextxy(x + stroke_distance, y + stroke_distance, w, strText.c_str());

	setcolor(color);
	scrollmidprinty(strText, y, w, midx, midx);
}
int WMAPI xyprintf_shadow(int x, int y, const char* szFormat, ...)
{
	constexpr int shadow_distance{ 2 };
	char buffer[4096]{ "\0" };
	va_list va;
	va_start(va, szFormat);
	int ret = _vsnprintf(buffer, 4096, szFormat, va);
	va_end(va);

	RLColor ocolor{ getcolor() };
	//setcolor(RAYRGBA(5, 5, 5, ocolor.a * 0.5f));
	setcolor(GetTextShadowColor(ocolor));
	xyprintf(x + shadow_distance, y + shadow_distance, "%s", buffer);

	//DebugLog(buffer);
	setcolor(ocolor);
	xyprintf(x, y, "%s", buffer);
	return strlen(buffer);
}
int WMAPI flowprintf_shadow(int x, int y, bool flow, float phase0, const char* szFormat, ...)
{
	constexpr int shadow_distance{ 1 };
	char buffer[4096]{ "\0" };
	va_list va;
	va_start(va, szFormat);
	int ret = _vsnprintf(buffer, 4096, szFormat, va);
	va_end(va);

	RLColor ocolor{ getcolor() };
	setcolor(GetTextShadowColor(ocolor));
	flowprintf(x + shadow_distance, y + shadow_distance, flow, phase0, "%s", buffer);

	//DebugLog(buffer);
	setcolor(ocolor);
	flowprintf(x, y, flow, phase0, "%s", buffer);
	return strlen(buffer);
}
int WMAPI flowprintf_rotateshadow(int x, int y, bool flow, float phase0, float rotation, const char* szFormat, ...)
{
	constexpr int shadow_distance{ 1 };
	char buffer[4096]{ "\0" };
	va_list va;
	va_start(va, szFormat);
	int ret = _vsnprintf(buffer, 4096, szFormat, va);
	va_end(va);

	RLColor ocolor{ getcolor() };
	setcolor(GetTextShadowColor(ocolor));
	flowprintf_rotate(x + shadow_distance, y + shadow_distance, false, phase0, rotation, "%s", buffer);

	//DebugLog(buffer);
	setcolor(ocolor);
	flowprintf_rotate(x, y, flow, phase0, rotation, "%s", buffer);
	return strlen(buffer);
}
int WMAPI scrollprintf_shadow(int x, int y, int w, const char* szFormat, ...)
{
	constexpr int shadow_distance{ 1 };
	char buffer[4096]{ "\0" };
	va_list va;
	va_start(va, szFormat);
	int ret = _vsnprintf(buffer, 4096, szFormat, va);
	va_end(va);

	RLColor ocolor{ getcolor() };
	setcolor(GetTextShadowColor(ocolor));
	scrollouttextxy(x + shadow_distance, y + shadow_distance, w, buffer);

	//DebugLog(buffer);
	setcolor(ocolor);
	scrollouttextxy(x, y, w, buffer);
	return strlen(buffer);
}
int WMAPI xyprintf_shadow(RLImage* pimg, int x, int y, const char* szFormat, ...)
{
	constexpr int shadow_distance{ 1 };
	char buffer[4096]{ "\0" };
	va_list va;
	va_start(va, szFormat);
	int ret = _vsnprintf(buffer, 4096, szFormat, va);
	va_end(va);

	RLColor ocolor{ getcolor() };
	setcolor(GetTextShadowColor(ocolor));
	xyprintf(pimg, x + shadow_distance, y + shadow_distance, "%s", buffer);

	//DebugLog(buffer);
	setcolor(ocolor);
	xyprintf(pimg, x, y, "%s", buffer);
	return strlen(buffer);
}
int WMAPI xyprintf_stroke(int x, int y, const char* szFormat, ...)
{
	constexpr int stroke_distance{ 1 };
	char buffer[4096]{ "\0" };
	va_list va;
	va_start(va, szFormat);
	int ret = _vsnprintf(buffer, 4096, szFormat, va);
	va_end(va);

	RLColor ocolor{ getcolor() };
	setcolor(GetTextShadowColor(ocolor));
	xyprintf(x - stroke_distance, y - stroke_distance, "%s", buffer);
	xyprintf(x - stroke_distance, y + stroke_distance, "%s", buffer);
	xyprintf(x + stroke_distance, y - stroke_distance, "%s", buffer);
	xyprintf(x + stroke_distance, y + stroke_distance, "%s", buffer);

	//DebugLog(buffer);
	setcolor(ocolor);
	xyprintf(x, y, "%s", buffer);
	return strlen(buffer);
}
int WMAPI xyprintf_stroke(RLImage* pimg, int x, int y, const char* szFormat, ...)
{
	constexpr int stroke_distance{ 1 };
	char buffer[4096]{ "\0" };
	va_list va;
	va_start(va, szFormat);
	int ret = _vsnprintf(buffer, 4096, szFormat, va);
	va_end(va);

	RLColor ocolor{ getcolor() };
	setcolor(GetTextShadowColor(ocolor));
	xyprintf(pimg, x - stroke_distance, y - stroke_distance, "%s", buffer);
	xyprintf(pimg, x - stroke_distance, y + stroke_distance, "%s", buffer);
	xyprintf(pimg, x + stroke_distance, y - stroke_distance, "%s", buffer);
	xyprintf(pimg, x + stroke_distance, y + stroke_distance, "%s", buffer);

	//DebugLog(buffer);
	setcolor(ocolor);
	xyprintf(pimg, x, y, "%s", buffer);
	return strlen(buffer);
}
void WMAPI alignprint(const string& strText, int y, int left = 0, int right = g.uix, const string& align = "Center", bool shadow = false)
{
	if (align == "Left")
	{
		if (shadow)
			xyprintf_shadow(left + 10, y, "%s", strText.c_str());
		else
			xyprintf(left + 10, y, "%s", strText.c_str());
	}
	else if (align == "Right")
	{
		int w = RLMeasureTextEx(g.font, strText.c_str(), g_fs, g_spacing).x;

		if (shadow)
			xyprintf_shadow(right - w - 10, y, "%s", strText.c_str());
		else
			xyprintf(right - w - 10, y, "%s", strText.c_str());
	}
	else if (align == "Center")
	{
		if (shadow)
			midprinty_shadow(strText, y, (left + right) / 2);
		else
			midprinty(strText, y, left, right);
	}
}

int centerprintf(const char* szFormat, ...)
{
	va_list va;
	va_start(va, szFormat);
	char buffer[1024] = "\0";
	int res = _vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	int x = g.uix / 2 - textwidth(buffer) / 2;
	int y = g.uiy / 2 - textheight(buffer) / 2;
	xyprintf(x, y, "%s", buffer);
	return res;
}
int centerprintf(RLImage* pimg, const char* szFormat, ...)
{
	va_list va;
	va_start(va, szFormat);
	char buffer[1024] = "\0";
	int res = _vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	int x = g.uix / 2 - textwidth(buffer) / 2;
	int y = g.uiy / 2 - textheight(buffer) / 2;
	xyprintf(pimg, x, y, "%s", buffer);
	return res;
}
int centerprintf_shadow(const char* szFormat, ...)
{
	va_list va;
	va_start(va, szFormat);
	char buffer[1024] = "\0";
	int res = _vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	int x = g.uix / 2 - textwidth(buffer) / 2;
	int y = g.uiy / 2 - textheight(buffer) / 2;
	xyprintf_shadow(x, y, "%s", buffer);
	return res;
}
int centerprintf_shadow(RLImage* pimg, const char* szFormat, ...)
{
	va_list va;
	va_start(va, szFormat);
	char buffer[1024] = "\0";
	int res = _vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	int x = g.uix / 2 - textwidth(buffer) / 2;
	int y = g.uiy / 2 - textheight(buffer) / 2;
	xyprintf_shadow(pimg, x, y, "%s", buffer);
	return res;
}
int midprintf(int y, const char* szFormat, ...)
{
	va_list va;
	va_start(va, szFormat);
	char buffer[1024] = "\0";
	int res = _vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	int x = g.uix / 2 - textwidth(buffer) / 2;
	RLDrawTextEx(g.font, buffer, MakeVector2((x), (y)), g_fs, g_spacing, g_fore_color);
	//xyprintf(x, y, buffer);
	return res;
}
int midprintf(RLImage* pimg, int y, const char* szFormat, ...)
{
	if (!pimg)
		return 0;
	va_list va;
	va_start(va, szFormat);
	char buffer[1024] = "\0";
	int res = _vsnprintf(buffer, 1024, szFormat, va);
	va_end(va);
	int x = g.uix / 2 - textwidth(buffer) / 2;
	RLImageDrawTextEx(pimg, g.font, buffer, MakeVector2(x, y), g_fs, g_spacing, g_fore_color);
	//xyprintf(x, y, buffer);
	return res;
}

inline HFONT WMAPI CreateFontA(int height, int width, LPCSTR lpFamilyName)
{
	return CreateFont(height, width, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, lpFamilyName);
}
//[[depreciated]] void BeginDraw()
//{
//	g.hdc = BeginPaint(g.hwnd, &g.ps);
//	g.hFontText = CreateFontA(g_fs, 0, "微软雅黑");
//	SelectObject(g.hdcBuffer, g.hFontText);
//	SetBkMode(g.hdcBuffer, TRANSPARENT);
//}
//[[depreciated]] void EndDraw()
//{
//	DeleteObject(g.hFontText);
//	EndPaint(g.hwnd, &g.ps);
//}
//[[depreciated]] void LoadGDI()
//{
//	g.hdcBuffer = CreateCompatibleDC(NULL);
//}
//[[depreciated]] void UnloadGDI()
//{
//	if (g.hdcBuffer)
//		DeleteDC(g.hdcBuffer), g.hdcBuffer = nullptr;
//	if (g.hBitmap)
//		DeleteObject(g.hBitmap), g.hBitmap = nullptr;
//}
//[[depreciated]] void BeginGDIDraw()
//{
//	BeginDraw();
//
//	// 获取客户区域的大小
//	RECT rcClient;
//	GetClientRect(g.hwnd, &rcClient);
//	int clientWidth = rcClient.right - rcClient.left;
//	int clientHeight = rcClient.bottom - rcClient.top;
//
//	// 创建双缓冲
//	if (g.hBitmap)
//		DeleteObject(g.hBitmap);
//	g.hBitmap = CreateCompatibleBitmap(g.hdc, clientWidth, clientHeight);
//	SelectObject(g.hdcBuffer, g.hBitmap);
//}
//[[depreciated]] void EndGDIDraw()
//{
//	// 获取客户区域的大小
//	RECT rcClient;
//	GetClientRect(g.hwnd, &rcClient);
//	int clientWidth = rcClient.right - rcClient.left;
//	int clientHeight = rcClient.bottom - rcClient.top;
//
//	// 将缓冲区的内容一次性绘制到屏幕上
//	BitBlt(g.hdc, 0, 0, clientWidth, clientHeight, g.hdcBuffer, 0, 0, SRCCOPY);
//	EndDraw();
//}
//
//[[depreciated]] void rawouttextxy(int x, int y, int fs, const char* fontname, const char* szText)
//{
//	BeginPaint(g.hwnd, &g.ps);
//	HDC hdc = g.hdc;
//	HFONT hFont = CreateFontA(fs, 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, fontname);
//	SelectObject(hdc, hFont);
//	SetBkMode(hdc, TRANSPARENT);
//	SetTextColor(hdc, RGB(g_fore_color.r, g_fore_color.g, g_fore_color.b));
//	TextOutA(hdc, x, y, szText, strlen(szText));
//	DeleteObject(hFont);
//	EndPaint(g.hwnd, &g.ps);
//}
//[[depreciated]] int rawxyprintf(int x, int y, int fs, const char* fontname, const char* szFormat, ...)
//{
//	va_list va;
//	va_start(va, szFormat);
//	char buffer[1024] = "\0";
//	int res = _vsnprintf(buffer, 1024, szFormat, va);
//	va_end(va);
//
//	rawouttextxy(x, y, fs, fontname, buffer);
//
//	return res;
//}

inline bool MyIsWindowFocused()
{
	return (g.hwnd == g.hwnd_foreground);
}
void CopyImageData(RLImage* imgDst, RLImage* imgSrc)
{
	for (int y = 0; y < imgSrc->height; ++y)
		for (int x = 0; x < imgSrc->width; ++x)
		{
			((RLColor*)(imgDst->data))[y * imgSrc->width + x] = ((RLColor*)(imgSrc->data))[y * imgSrc->width + x];
		}
}
void MyImageFlipHorizontal(RLImage* pimg)
{
	RLImage img = RLImageCopy(*pimg);
	RLImageFlipHorizontal(&img);
	CopyImageData(pimg, &img);
	RLUnloadImage(img);
}
void MyImageFlipVertical(RLImage* pimg)
{
	RLImage img = RLImageCopy(*pimg);
	RLImageFlipVertical(&img);
	CopyImageData(pimg, &img);
	RLUnloadImage(img);
}
void FlipImage(RLImage* pimg, DIR2 dir)
{
	if (!pimg || !RLIsImageValid(*pimg))
		return;

	if (dir == HORIZ)
		MyImageFlipHorizontal(pimg);
	else
		MyImageFlipVertical(pimg);
}
void MyImageColorTint(RLImage* pimg, RLColor tint)
{
	if (!pimg || !RLIsImageValid(*pimg))
		return;
	RLImage img = RLImageCopy(*pimg);
	RLImageColorTint(&img, tint);
	CopyImageData(pimg, &img);
	RLUnloadImage(img);
}
void MyImageColorBrightness(RLImage* pimg, int brightness)
{
	if (!pimg || !RLIsImageValid(*pimg))
		return;
	RLImage img = RLImageCopy(*pimg);
	RLImageColorBrightness(&img, brightness);
	CopyImageData(pimg, &img);
	RLUnloadImage(img);
}
//void DarkenImage(Image* pimg, Lightness lightness)
//{
//	MyImageColorBrightness(pimg, lightness - 255);
//}
void SemialphaImage(RLImage* pimg)
{
	MyImageColorTint(pimg, RAYRGBA(255, 255, 255, 127));
}
void SetImageAlpha(RLImage* pimg, int alpha)
{
	MyImageColorTint(pimg, RLColorAlpha(RAYWHITE, alpha / 255.0f));
}

#define ROT_COEFF 60.0
#define ROT_PHASE ( - PI / 2.0f)

inline float RotationFormula(float rotation)
{
	return (PI / 2.0f - rotation + ROT_PHASE) * ROT_COEFF;
}
//#define NO_QUICKDRAW_TEXTURE_CHECK
void QuickDraw(const RLImage* pimgSrc, double x, double y, float alpha_rat = 1.0, RLColor tint = WHITE)
{
	if (!pimgSrc)	return;
	RLTexture texture = RLLoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!RLIsTextureValid(texture))
		return;
#endif

	RLDrawTexture(texture, (x), (y), RLColorAlpha(tint, alpha_rat));

	
		g.frame_textures.push_back(texture);
}
void QuickDraw(const RLImage* pimgSrc, double x, double y, double src_x, double src_y, double src_w, double src_h, float alpha_rat = 1.0, RLColor tint = WHITE)
{
	if (!pimgSrc)	return;
	RLTexture texture = RLLoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!RLIsTextureValid(texture))
		return;
#endif
	RLDrawTexturePro(texture, MakeRectangle0(src_x, src_y, src_w, src_h), MakeRectangle0((x), (y), src_w, src_h),
		RLVector2{ 0.5f * pimgSrc->width, 0.5f * pimgSrc->height }, 0.0f, RLColorAlpha(tint, alpha_rat));
	
		g.frame_textures.push_back(texture);
}
void QuickDraw(const RLImage* pimgSrc, double dst_x, double dst_y, double dst_w, double dst_h, double src_x, double src_y, double src_w, double src_h, float alpha_rat = 1.0, RLColor tint = WHITE)
{
	if (!pimgSrc)	return;

	//QuickDraw(pimgSrc, dst_x, dst_y, alpha_rat);

	RLTexture texture = RLLoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!RLIsTextureValid(texture))
		return;
#endif
	RLDrawTexturePro(texture, MakeRectangle0(src_x, src_y, src_w, src_h), MakeRectangle0((dst_x), (dst_y), dst_w, dst_h),
		//Vector2{ 0.5f * pimgSrc->width, 0.5f * pimgSrc->height }, 
		RLVector2{ 0.0f, 0.0f },
		0.0f, RLColorAlpha(tint, alpha_rat));
	
		g.frame_textures.push_back(texture);
}
void QuickDrawRotate(const RLImage* pimgSrc, double x, double y, float rotation, float alpha_rat = 1.0, RLColor tint = WHITE)
{
	if (!pimgSrc)	return;
	RLTexture texture = RLLoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!RLIsTextureValid(texture))
		return;
#endif
	RLDrawTextureEx(texture, MakeVector2((x), (y)), RotationFormula(rotation), 1.0f, RLColorAlpha(tint, alpha_rat));
	
		g.frame_textures.push_back(texture);
}
void QuickDrawRotateEx(const RLImage* pimgSrc, double x, double y, float rotation, float center_x = 0.5f, float center_y = 0.5f, float alpha_rat = 1.0, RLColor tint = WHITE)
{
	if (!pimgSrc)	return;
	RLTexture texture = RLLoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!RLIsTextureValid(texture))
		return;
#endif
	RLDrawTexturePro(texture, MakeRectangle0(0, 0, pimgSrc->width, pimgSrc->height),
		MakeRectangle0((x), (y), pimgSrc->width, pimgSrc->height),
		RLVector2{ center_x * pimgSrc->width, center_y * pimgSrc->height },
		RotationFormula(rotation), RLColorAlpha(tint, alpha_rat));
	
		g.frame_textures.push_back(texture);
}
void QuickDrawZoom(const RLImage* pimgSrc, double x, double y, float scale, float alpha_rat = 1.0, RLColor tint = WHITE)
{
	if (!pimgSrc)	return;
	RLTexture texture = RLLoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!RLIsTextureValid(texture))
		return;
#endif
	RLDrawTextureEx(texture, MakeVector2((x), (y)), 0.0f, scale, RLColorAlpha(tint, alpha_rat));
	
		g.frame_textures.push_back(texture);
}
void QuickDrawRotateZoom(const RLImage* pimgSrc, double x, double y, float rotation, float scale, float alpha_rat = 1.0, RLColor tint = WHITE)
{
	if (!pimgSrc)	return;
	RLTexture texture = RLLoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!RLIsTextureValid(texture))
		return;
#endif
	RLDrawTextureEx(texture, MakeVector2((x), (y)),
		RotationFormula(rotation), scale, RLColorAlpha(tint, alpha_rat));
	
		g.frame_textures.push_back(texture);
}
void QuickDrawRotateZoomEx(const RLImage* pimgSrc, double x, double y, float center_x, float center_y, float rotation, float scale, float alpha_rat = 1.0, RLColor tint = WHITE)
{
	if (!pimgSrc)	return;
	RLTexture texture = RLLoadTextureFromImage(*pimgSrc);
#ifndef NO_QUICKDRAW_TEXTURE_CHECK
	if (!RLIsTextureValid(texture))
		return;
#endif
	RLDrawTexturePro(texture, MakeRectangle0(0, 0, pimgSrc->width, pimgSrc->height),
		MakeRectangle0((x), (y), pimgSrc->width * scale, pimgSrc->height * scale), RLVector2{ center_x * pimgSrc->width, center_y * pimgSrc->height },
		RotationFormula(rotation), RLColorAlpha(tint, alpha_rat));
	
		g.frame_textures.push_back(texture);
}

///////////////////////////////////////////////////////////
//                  Control 控制系列                      //
///////////////////////////////////////////////////////////

inline bool IsFocused()
{
	return g.hwnd_foreground == g.hwnd;
}

void OnMouseWheel(int delta, bool gui = true, bool global = true);

LRESULT CALLBACK RawInputProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (uMsg == WM_INPUT) {

		if (g.quitting || !g.loaded) {
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}

		RAWINPUT raw;
		UINT size = sizeof(raw);
		GetRawInputData(reinterpret_cast<HRAWINPUT>(lParam), RID_INPUT, &raw, &size, sizeof(RAWINPUTHEADER));
		if (raw.header.dwType == RIM_TYPEMOUSE && g.loaded && !g.quitting) {
			if (raw.data.mouse.usButtonFlags == RI_MOUSE_WHEEL) {

				short wheelDelta = static_cast<short>(raw.data.mouse.usButtonData);
				if (wheelDelta > 0) {
					g.pending_raw_wheel_delta.fetch_add(-1);
				}
				else {
					g.pending_raw_wheel_delta.fetch_add(1);
				}
			}
		}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

DWORD MouseWheelDetectionProc(LPVOID none);
void StartMouseWheelDetectionWorker();
void RequestStopMouseWheelDetectionWorker();
void StopMouseWheelDetectionWorker();

//bool SetClipboardDIBV5(const Image& img)
//{
//	auto data = RayImageToBGRA(img);
//	int width = img.width;
//	int height = img.height;
//
//	BITMAPV5HEADER bmh = {};
//	bmh.bV5Size = sizeof(BITMAPV5HEADER);
//	bmh.bV5Width = width;
//	bmh.bV5Height = -height; // top-down DIBV5
//	bmh.bV5Planes = 1;
//	bmh.bV5BitCount = 32;
//	bmh.bV5Compression = BI_BITFIELDS;
//	bmh.bV5RedMask = 0x00FF0000;
//	bmh.bV5GreenMask = 0x0000FF00;
//	bmh.bV5BlueMask = 0x000000FF;
//	bmh.bV5AlphaMask = 0xFF000000;
//
//	SIZE_T totalSize = sizeof(BITMAPV5HEADER) + width * height * 4;
//
//	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, totalSize);
//	if (!hMem) return false;
//
//	BYTE* pMem = (BYTE*)GlobalLock(hMem);
//
//	memcpy(pMem, &bmh, sizeof(bmh));
//	memcpy(pMem + sizeof(bmh), data.data(), width * height * 4);
//
//	GlobalUnlock(hMem);
//
//	OpenClipboard(nullptr);
//	SetClipboardData(CF_DIBV5, hMem);
//	CloseClipboard();
//
//	return true;
//}
HBITMAP CreateHBITMAPFromImage(const RLImage& img)
{
	BITMAPINFO bmi = {};
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = img.width;
	bmi.bmiHeader.biHeight = -img.height; // top-down
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;

	void* bits = nullptr;
	HBITMAP hBmp = CreateDIBSection(nullptr, &bmi, DIB_RGB_COLORS, &bits, nullptr, 0);
	if (!hBmp) return nullptr;

	DWORD* dst = (DWORD*)bits;
	RLColor* src = (RLColor*)img.data;

	for (int i = 0; i < img.width * img.height; i++)
	{
		dst[i] =
			(src[i].b) |
			(src[i].g << 8) |
			(src[i].r << 16);
	}

	return hBmp;
}

HGLOBAL CreatePNG_HGLOBAL_WIC(const RLImage& img)
{
	HRESULT hr = S_OK;
	IWICImagingFactory* factory = nullptr;
	IWICBitmap* bitmap = nullptr;
	IWICBitmapEncoder* encoder = nullptr;
	IWICBitmapFrameEncode* frame = nullptr;
	IStream* stream = nullptr;
	WICPixelFormatGUID format = GUID_WICPixelFormat32bppRGBA;
	HGLOBAL hMem = nullptr;

	CoInitialize(nullptr);

	hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(&factory));
	if (FAILED(hr)) goto cleanup;

	// img.data 必须是 RGBA8888（raylib 常见格式）
	hr = factory->CreateBitmapFromMemory(
		img.width, img.height,
		GUID_WICPixelFormat32bppRGBA,
		img.width * 4,
		img.width * img.height * 4,
		(BYTE*)img.data,
		&bitmap
	);
	if (FAILED(hr)) goto cleanup;

	// ✅ 关键：FALSE，避免 stream->Release() 自动释放 HGLOBAL
	hr = CreateStreamOnHGlobal(nullptr, FALSE, &stream);
	if (FAILED(hr)) goto cleanup;

	hr = factory->CreateEncoder(GUID_ContainerFormatPng, nullptr, &encoder);
	if (FAILED(hr)) goto cleanup;

	hr = encoder->Initialize(stream, WICBitmapEncoderNoCache);
	if (FAILED(hr)) goto cleanup;

	hr = encoder->CreateNewFrame(&frame, nullptr);
	if (FAILED(hr)) goto cleanup;

	hr = frame->Initialize(nullptr);
	if (FAILED(hr)) goto cleanup;

	hr = frame->SetSize(img.width, img.height);
	if (FAILED(hr)) goto cleanup;

	hr = frame->SetPixelFormat(&format);
	if (FAILED(hr)) goto cleanup;

	hr = frame->WriteSource(bitmap, nullptr);
	if (FAILED(hr)) goto cleanup;

	hr = frame->Commit();
	if (FAILED(hr)) goto cleanup;

	hr = encoder->Commit();
	if (FAILED(hr)) goto cleanup;

	// 取出 HGLOBAL
	hr = GetHGlobalFromStream(stream, &hMem);
	if (FAILED(hr) || !hMem) goto cleanup;

	// 可选自检：必须 > 0
	if (GlobalSize(hMem) == 0) { hMem = nullptr; goto cleanup; }

cleanup:
	if (frame) frame->Release();
	if (encoder) encoder->Release();
	if (bitmap) bitmap->Release();
	if (factory) factory->Release();
	if (stream) stream->Release();
	CoUninitialize();

	return hMem; // 成功返回有效 PNG 的 HGLOBAL（大小应 > 0）
}

HGLOBAL CreateDIB_HGLOBAL(RLImage img) {
	int width = img.width;
	int height = img.height;

	// DWORD 对齐
	int stride = ((width * 32 + 31) / 32) * 4;
	int pixelSize = stride * height;

	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, sizeof(BITMAPINFOHEADER) + pixelSize);
	if (!hMem) return nullptr;

	BYTE* pMem = (BYTE*)GlobalLock(hMem);
	if (!pMem) return nullptr;

	BITMAPINFOHEADER* bih = (BITMAPINFOHEADER*)pMem;
	ZeroMemory(bih, sizeof(*bih));

	bih->biSize = sizeof(BITMAPINFOHEADER);
	bih->biWidth = width;
	bih->biHeight = height;              // ✅ bottom-up
	bih->biPlanes = 1;
	bih->biBitCount = 32;
	bih->biCompression = BI_RGB;
	bih->biSizeImage = pixelSize;

	BYTE* dst = pMem + sizeof(BITMAPINFOHEADER);
	memset(dst, 0, pixelSize);

	RLColor* src = (RLColor*)img.data;

	// bottom-up 拷贝
	for (int y = 0; y < height; y++)
	{
		BYTE* row = dst + (height - 1 - y) * stride;
		for (int x = 0; x < width; x++)
		{
			RLColor c = src[y * width + x];
			row[x * 4 + 0] = c.b;
			row[x * 4 + 1] = c.g;
			row[x * 4 + 2] = c.r;
			row[x * 4 + 3] = 0xFF;
		}
	}

	GlobalUnlock(hMem);

	return hMem;
}

bool SetClipboardImage(const RLImage& img, bool png, bool dib)
{
	static UINT CF_PNG = RegisterClipboardFormatA("PNG");

	HGLOBAL hPng = png ? CreatePNG_HGLOBAL_WIC(img) : nullptr;
	HGLOBAL hDib = dib ? CreateDIB_HGLOBAL(img) : nullptr;
	HBITMAP hBmp = CreateHBITMAPFromImage(img);

	if (!hPng && !hDib && !hBmp)
		return false;

	if (!OpenClipboard(nullptr))
		return false;

	EmptyClipboard();

	if (hPng)
		SetClipboardData(CF_PNG, hPng);

	if (hDib)
		SetClipboardData(CF_DIB, hDib);

	if (hBmp)
		SetClipboardData(CF_BITMAP, hBmp); // ⭐⭐ 关键

	CloseClipboard();

	return true;
}

void TakeRealScreenshotInto(uint8_t* dst, int left, int top, int width, int height, HWND hwnd = nullptr);

RLImage TakeRealScreenshot(int left, int top, int width, int height, HWND hwnd /*= nullptr*/)
{
	if (0 == width) {
		width = hwnd ? GetWindowWidth(hwnd) : g.uix;
	}
	if (0 == height) {
		height = hwnd ? GetWindowHeight(hwnd) : g.uiy;
	}

	RLImage img{};
	if (width <= 0 || height <= 0) return img;

	std::vector<uint8_t> bgra((size_t)width * (size_t)height * 4ULL);
	TakeRealScreenshotInto(bgra.data(), left, top, width, height, hwnd);

	img.width = width;
	img.height = height;
	img.mipmaps = 1;
	img.format = RL_E_PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
	img.data = RLMemAlloc((int)bgra.size());
	if (!img.data) {
		img = RLImage{};
		return img;
	}

	uint8_t* dst = (uint8_t*)img.data;
	for (size_t i = 0; i < bgra.size(); i += 4) {
		dst[i + 0] = bgra[i + 2];
		dst[i + 1] = bgra[i + 1];
		dst[i + 2] = bgra[i + 0];
		dst[i + 3] = bgra[i + 3];
	}
	return img;
}

void TakeRealScreenshotInto(uint8_t* dst, int left, int top, int width, int height, HWND hwnd)
{
	if (width == 0) width = hwnd ? GetWindowWidth(hwnd) : g.uix;
	if (height == 0) height = hwnd ? GetWindowHeight(hwnd) : g.uiy;

	HDC hdc = GetWindowDC(hwnd);
	HDC hMemDC = CreateCompatibleDC(hdc);
	HBITMAP hBitmap = CreateCompatibleBitmap(hdc, width, height);
	SelectObject(hMemDC, hBitmap);

	BOOL pwSuccess = hwnd ? PrintWindow(hwnd, hMemDC, PW_RENDERFULLCONTENT) : FALSE;
	if (!pwSuccess) BitBlt(hMemDC, 0, 0, width, height, hdc, left, top, SRCCOPY);

	BITMAPINFO bmi{};
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biHeight = -height; // 从上到下
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;

	// 注意：GetDIBits 直接写进 dst（B,G,R,A）
	GetDIBits(hMemDC, hBitmap, 0, height, dst, &bmi, DIB_RGB_COLORS);

	DeleteObject(hBitmap);
	DeleteDC(hMemDC);
	ReleaseDC(hwnd, hdc);
}


void DrawRectangleRounded2(RLRectangle rec, float roundness, int segments, RLColor color)
{
	RLRectangle rec2{ rec };
	rec2.x = (rec2.x);
	rec2.y = (rec2.y);
	
	if (g.config.gui_config.contains("Round Corners") && g.config.gui_config["Round Corners"].get<bool>())
		RLDrawRectangleRounded(rec2, roundness, segments, color);
	else
		RLDrawRectangle(rec2.x, rec2.y, rec2.width, rec2.height, color);
}
void DrawRectangleRoundedDecision(RLRectangle rec, float roundness, int segments, RLColor color, bool round_corners)
{
	RLRectangle rec2{ rec };
	rec2.x = (rec2.x);
	rec2.y = (rec2.y);
	if (round_corners)
		RLDrawRectangleRounded(rec2, roundness, segments, color);
	else
		RLDrawRectangle(rec2.x, rec2.y, rec2.width, rec2.height, color);
}
void DrawRectangleRoundedLines2(RLRectangle rec, float roundness, int segments, float lineThick, RLColor color)
{
	RLRectangle rec2{ rec };
	rec2.x = (rec2.x);
	rec2.y = (rec2.y);
	if (g.config.gui_config.contains("Round Corners") && g.config.gui_config["Round Corners"].get<bool>())
		RLDrawRectangleRoundedLinesEx(rec2, roundness, segments, lineThick, color);
	else
        RLDrawRectangleLinesEx(rec2, lineThick, color);
}
void DrawRectangleRoundedLinesDecision(RLRectangle rec, float roundness, int segments, float lineThick, RLColor color, bool round_corners)
{
	RLRectangle rec2{ rec };
	rec2.x = (rec2.x);
	rec2.y = (rec2.y);
	if (round_corners)
		RLDrawRectangleRoundedLinesEx(rec2, roundness, segments, lineThick, color);
	else
		RLDrawRectangleLinesEx(rec2, lineThick, color);
}
void DrawRectangleRoundedShadowDecisionM(RLRectangle rec, float roundness, int segments,
	RLColor color, bool round_corners, bool shadow, float shadow_thick = 10.0f,
	RLColor shadowColor = BLACK, bool oldMethod = false, bool softNew = false)
{
	RLRectangle rec2{ rec };

	if (oldMethod) {
		if (shadow) {
			RLColor emptyColor = ColorAlpha2(shadowColor, 0.0f);
			// Quantize once for all old-gradient passes to avoid 1px seams caused by
			// mixed float->int truncation across adjacent quads.
			int rx = (int)floorf(rec2.x + 0.5f);
			int ry = (int)floorf(rec2.y + 0.5f);
			int rw = max(1, (int)floorf(rec2.width + 0.5f));
			int rh = max(1, (int)floorf(rec2.height + 0.5f));
			int st = max(1, (int)ceilf(shadow_thick));

			float radius = 0.0f;
			if (round_corners) {
				// raylib 的 roundness 是 0~1，半径大致是 min(w,h) * roundness / 2
				float minSide = (rw < rh) ? (float)rw : (float)rh;
				radius = roundness * minSide / 2.0f;
				if (radius < 0.0f) radius = 0.0f;
			}

			//if (!round_corners || radius <= 0.0f) {
			if constexpr (true) {
				// =============================
				// 没有圆角：用你原来的逻辑
				// =============================
				// 顶/底
				RLDrawRectangleGradientV(rx,
					ry - st,
					rw,
					st,
					emptyColor,
					shadowColor);

				RLDrawRectangleGradientV(rx,
					ry + rh,
					rw,
					st,
					shadowColor,
					emptyColor);

				// 四角
				RLDrawRectangleGradientEx(
					MakeRectangle0((float)(rx - st), (float)(ry - st),
						(float)st, (float)st),
					emptyColor, emptyColor, shadowColor, emptyColor);

				RLDrawRectangleGradientEx(
					MakeRectangle0((float)(rx - st), (float)(ry + rh),
						(float)st, (float)st),
					emptyColor, emptyColor, emptyColor, shadowColor);

				RLDrawRectangleGradientEx(
					MakeRectangle0((float)(rx + rw), (float)(ry - st),
						(float)st, (float)st),
					emptyColor, shadowColor, emptyColor, emptyColor);

				RLDrawRectangleGradientEx(
					MakeRectangle0((float)(rx + rw), (float)(ry + rh),
						(float)st, (float)st),
					shadowColor, emptyColor, emptyColor, emptyColor);

				// 左右
				RLDrawRectangleGradientH(rx - st,
					ry,
					st,
					rh,
					emptyColor,
					shadowColor);

				RLDrawRectangleGradientH(rx + rw,
					ry,
					st,
					rh,
					shadowColor,
					emptyColor);
			}
			//else {
			//	// =============================
			//	// 有圆角：边 + 圆形渐变角
			//	// =============================

			//	// 1) 四条边的阴影（缩掉两端 radius，让出角落）
			//	// 顶边
			//	DrawRectangleGradientV(
			//		rec2.x + radius,
			//		rec2.y - shadow_thick,
			//		rec2.width - radius * 2.0f,
			//		shadow_thick,
			//		emptyColor,
			//		shadowColor
			//	);

			//	// 底边
			//	DrawRectangleGradientV(
			//		rec2.x + radius,
			//		rec2.y + rec2.height,
			//		rec2.width - radius * 2.0f,
			//		shadow_thick,
			//		shadowColor,
			//		emptyColor
			//	);

			//	// 左边
			//	DrawRectangleGradientH(
			//		rec2.x - shadow_thick,
			//		rec2.y + radius,
			//		shadow_thick,
			//		rec2.height - radius * 2.0f,
			//		emptyColor,
			//		shadowColor
			//	);

			//	// 右边
			//	DrawRectangleGradientH(
			//		rec2.x + rec2.width,
			//		rec2.y + radius,
			//		shadow_thick,
			//		rec2.height - radius * 2.0f,
			//		shadowColor,
			//		emptyColor
			//	);

			//	//// 2) 四个角的圆形渐变阴影
			//	//float cornerRadius = (radius + shadow_thick) * 1.5f;

			//	//// 左上角
			//	//DrawCircleGradient(
			//	//	(int)(rec2.x + radius),
			//	//	(int)(rec2.y + radius),
			//	//	cornerRadius,
			//	//	shadowColor,      // 中心：阴影色（会被后面的矩形盖住一部分）
			//	//	emptyColor        // 外圈：透明
			//	//);

			//	//// 右上角
			//	//DrawCircleGradient(
			//	//	(int)(rec2.x + rec2.width - radius),
			//	//	(int)(rec2.y + radius),
			//	//	cornerRadius,
			//	//	shadowColor,
			//	//	emptyColor
			//	//);

			//	//// 左下角
			//	//DrawCircleGradient(
			//	//	(int)(rec2.x + radius),
			//	//	(int)(rec2.y + rec2.height - radius),
			//	//	cornerRadius,
			//	//	shadowColor,
			//	//	emptyColor
			//	//);

			//	//// 右下角
			//	//DrawCircleGradient(
			//	//	(int)(rec2.x + rec2.width - radius),
			//	//	(int)(rec2.y + rec2.height - radius),
			//	//	cornerRadius,
			//	//	shadowColor,
			//	//	emptyColor
			//	//);
			//	// 2) 四个角的矩形渐变阴影（替代 DrawCircleGradient）
			//	// 2) 四个角的矩形渐变阴影（保持你的颜色，只调整位置/大小）
			//	float corner = radius + shadow_thick;

			//	// 往外再推一点（越大阴影越“散”）
			//	float push = 0.0f;//radius * 0.5f;   // 可以自己调 0.3f ~ 0.8f 之间试

			//	// 左上角：往左上推
			//	DrawRectangleGradientEx(
			//		MakeRectangle0(
			//			rec2.x - shadow_thick - push,      // x
			//			rec2.y - shadow_thick - push,      // y
			//			corner + push,                     // w
			//			corner + push                      // h
			//		),
			//		emptyColor,    // TL
			//		emptyColor,    // BL
			//		shadowColor,   // TR
			//		emptyColor     // BR
			//	);

			//	// 右上角：往右上推
			//	DrawRectangleGradientEx(
			//		MakeRectangle0(
			//			rec2.x + rec2.width - corner + shadow_thick + push,
			//			rec2.y - shadow_thick - push,
			//			corner - push,
			//			corner + push
			//		),
			//		emptyColor,
			//		shadowColor,   // 这一项保持不动
			//		emptyColor,
			//		emptyColor
			//	);

			//	// 左下角：往左下推
			//	DrawRectangleGradientEx(
			//		MakeRectangle0(
			//			rec2.x - shadow_thick - push,
			//			rec2.y + rec2.height - corner + shadow_thick + push,
			//			corner + push,
			//			corner - push
			//		),
			//		emptyColor,
			//		emptyColor,
			//		emptyColor,
			//		shadowColor    // 仍然只有这里是阴影色
			//	);

			//	// 右下角：往右下推
			//	DrawRectangleGradientEx(
			//		MakeRectangle0(
			//			rec2.x + rec2.width - corner + shadow_thick + push,
			//			rec2.y + rec2.height - corner + shadow_thick + push,
			//			corner - push,
			//			corner - push
			//		),
			//		shadowColor,   // 保持你的分布
			//		emptyColor,
			//		emptyColor,
			//		emptyColor
			//	);
			//}
		}
	}
	else {
		RLRectangle rec2 = rec;

		if (shadow && shadow_thick > 0.0f) {
			if (softNew) {
				// 性能优化：非常小厚度显著减层；中等厚度提高层数，保证 HUD 观感。
				int layers = 8;
				if (shadow_thick <= 8.0f) {
					layers = (int)Clamp(2.0f + shadow_thick * 0.65f, 3.0f, 8.0f);
				}
				else if (shadow_thick <= 20.0f) {
					layers = (int)Clamp(8.0f + (shadow_thick - 8.0f) * 0.95f, 8.0f, 19.0f);
				}
				else {
					layers = (int)Clamp(19.0f + (shadow_thick - 20.0f) * 0.30f, 19.0f, 24.0f);
				}
				float ringStep = shadow_thick / (float)max(1, layers - 1);
				float lineThick = Clamp(ringStep * 2.05f + 0.2f, 1.0f, 3.0f); // 轻重叠，避免圈间缝

				float baseMinSide = max(1.0f, min(rec2.width, rec2.height));
				float baseRadiusPx = round_corners
					? Clamp(roundness, 0.0f, 1.0f) * baseMinSide * 0.5f
					: max(4.0f, min(baseMinSide * 0.24f, 16.0f)); // 非圆角也做柔和阴影角

				for (int i = 0; i < layers; ++i) {
					float t = (float)i / (float)max(1, layers - 1); // 内->外
					float expand = ringStep * (float)i; // i=0 贴住本体边缘，去除缝隙

					RLColor c = shadowColor;
					c.a = (unsigned char)Clamp((float)shadowColor.a * powf(1.0f - t, 1.45f), 0.0f, 255.0f);
					if (c.a <= 0) continue;

					RLRectangle r = {
						rec2.x - expand,
						rec2.y - expand,
						rec2.width + expand * 2.0f,
						rec2.height + expand * 2.0f
					};

					float minSide = max(1.0f, min(r.width, r.height));
					float radiusPx = baseRadiusPx + expand;
					float rr = Clamp(radiusPx / (minSide * 0.5f), 0.0f, 1.0f);
					rr = min(rr, 0.98f);

					RLDrawRectangleRoundedLinesEx(r, rr, max(10, segments), lineThick, c);
				}
			}
			else {
				/* =============================
				   阴影（Outdated：多层外扩描边）
				   ============================= */
				int layers = (int)shadow_thick;
				if (layers < 1) layers = 1;

				for (int i = 1; i <= layers; ++i) {
					float t = 1.0f - (float)i / (float)layers;
					unsigned char a = (unsigned char)(shadowColor.a * t);
					if (a <= 2) continue;

					RLColor c = shadowColor;
					c.a = a;

					float expand = (float)i;
					RLRectangle r = {
						rec2.x - expand,
						rec2.y - expand,
						rec2.width + expand * 2.0f,
						rec2.height + expand * 2.0f
					};

					if (round_corners) {
						RLDrawRectangleRoundedLinesEx(r, roundness, segments, 1.5f, c);
					}
					else {
						RLDrawRectangleLinesEx(r, 1.5f, c);
					}
				}
			}
		}
	}

	// =============================
	// 最后画矩形本体
	// =============================
	if (RLColorToInt(color) != RLColorToInt(BLANK)) {
		if (round_corners)
			RLDrawRectangleRounded(rec2, roundness, segments, color);
		else
			RLDrawRectangle(rec2.x, rec2.y, rec2.width, rec2.height, color);
	}
}

void DrawRectangleRoundedShadowDecision(RLRectangle rec, float roundness, int segments,
	RLColor color, bool round_corners, bool shadow, float shadow_thick /*= 10.0f*/,
	RLColor shadowColor /*= BLACK*/) {
	string method = XCPT_VALUE(GET_COMBOBOX(g.config.gui_config["Shadow Rendering Method"]).get<string>(), "Outdated");
	bool oldMethod = (method == "Old");
	bool softNew = (method == "New");
	DrawRectangleRoundedShadowDecisionM(rec, roundness, segments, color, round_corners, shadow, shadow_thick,
		shadowColor, oldMethod, softNew);
}
static const std::unordered_map<UINT, int> VK_TO_RAYLIB = {

	// -------- Punctuation --------
	{ VK_OEM_1,        RL_E_KEY_SEMICOLON },      // ; :
	{ VK_OEM_PLUS,     RL_E_KEY_EQUAL },          // =
	{ VK_OEM_COMMA,    RL_E_KEY_COMMA },          // ,
	{ VK_OEM_MINUS,    RL_E_KEY_MINUS },          // -
	{ VK_OEM_PERIOD,   RL_E_KEY_PERIOD },         // .
	{ VK_OEM_2,        RL_E_KEY_SLASH },          // /
	{ VK_OEM_3,        RL_E_KEY_GRAVE },          // `
	{ VK_OEM_4,        RL_E_KEY_LEFT_BRACKET },   // [
	{ VK_OEM_5,        RL_E_KEY_BACKSLASH },      // '\'
	{ VK_OEM_6,        RL_E_KEY_RIGHT_BRACKET },  // ]
	{ VK_OEM_7,        RL_E_KEY_APOSTROPHE },     // '

	// -------- Function keys --------
	{ VK_ESCAPE,       RL_E_KEY_ESCAPE },
	{ VK_RETURN,       RL_E_KEY_ENTER },
	{ VK_TAB,          RL_E_KEY_TAB },
	{ VK_BACK,         RL_E_KEY_BACKSPACE },
	{ VK_INSERT,       RL_E_KEY_INSERT },
	{ VK_DELETE,       RL_E_KEY_DELETE },
	{ VK_RIGHT,        RL_E_KEY_RIGHT },
	{ VK_LEFT,         RL_E_KEY_LEFT },
	{ VK_DOWN,         RL_E_KEY_DOWN },
	{ VK_UP,           RL_E_KEY_UP },
	{ VK_PRIOR,        RL_E_KEY_PAGE_UP },
	{ VK_NEXT,         RL_E_KEY_PAGE_DOWN },
	{ VK_HOME,         RL_E_KEY_HOME },
	{ VK_END,          RL_E_KEY_END },
	{ VK_CAPITAL,      RL_E_KEY_CAPS_LOCK },
	{ VK_SCROLL,       RL_E_KEY_SCROLL_LOCK },
	{ VK_NUMLOCK,      RL_E_KEY_NUM_LOCK },
	{ VK_SNAPSHOT,     RL_E_KEY_PRINT_SCREEN },
	{ VK_PAUSE,        RL_E_KEY_PAUSE },

	{ VK_F1,           RL_E_KEY_F1 },
	{ VK_F2,           RL_E_KEY_F2 },
	{ VK_F3,           RL_E_KEY_F3 },
	{ VK_F4,           RL_E_KEY_F4 },
	{ VK_F5,           RL_E_KEY_F5 },
	{ VK_F6,           RL_E_KEY_F6 },
	{ VK_F7,           RL_E_KEY_F7 },
	{ VK_F8,           RL_E_KEY_F8 },
	{ VK_F9,           RL_E_KEY_F9 },
	{ VK_F10,          RL_E_KEY_F10 },
	{ VK_F11,          RL_E_KEY_F11 },
	{ VK_F12,          RL_E_KEY_F12 },

	// -------- Modifiers --------
	{ VK_SHIFT,        RL_E_KEY_LEFT_SHIFT },      // 若需区分左右请使用 VK_LSHIFT / VK_RSHIFT
	{ VK_LSHIFT,       RL_E_KEY_LEFT_SHIFT },
	{ VK_RSHIFT,       RL_E_KEY_RIGHT_SHIFT },

	{ VK_CONTROL,      RL_E_KEY_LEFT_CONTROL },
	{ VK_LCONTROL,     RL_E_KEY_LEFT_CONTROL },
	{ VK_RCONTROL,     RL_E_KEY_RIGHT_CONTROL },

	{ VK_MENU,         RL_E_KEY_LEFT_ALT },
	{ VK_LMENU,        RL_E_KEY_LEFT_ALT },
	{ VK_RMENU,        RL_E_KEY_RIGHT_ALT },

	{ VK_LWIN,         RL_E_KEY_LEFT_SUPER },
	{ VK_RWIN,         RL_E_KEY_RIGHT_SUPER },

	// -------- Keypad --------
	{ VK_NUMPAD0,      RL_E_KEY_KP_0 },
	{ VK_NUMPAD1,      RL_E_KEY_KP_1 },
	{ VK_NUMPAD2,      RL_E_KEY_KP_2 },
	{ VK_NUMPAD3,      RL_E_KEY_KP_3 },
	{ VK_NUMPAD4,      RL_E_KEY_KP_4 },
	{ VK_NUMPAD5,      RL_E_KEY_KP_5 },
	{ VK_NUMPAD6,      RL_E_KEY_KP_6 },
	{ VK_NUMPAD7,      RL_E_KEY_KP_7 },
	{ VK_NUMPAD8,      RL_E_KEY_KP_8 },
	{ VK_NUMPAD9,      RL_E_KEY_KP_9 },

	{ VK_DECIMAL,      RL_E_KEY_KP_DECIMAL },
	{ VK_DIVIDE,       RL_E_KEY_KP_DIVIDE },
	{ VK_MULTIPLY,     RL_E_KEY_KP_MULTIPLY },
	{ VK_SUBTRACT,     RL_E_KEY_KP_SUBTRACT },
	{ VK_ADD,          RL_E_KEY_KP_ADD },
	{ VK_SEPARATOR,    RL_E_KEY_KP_EQUAL },   // 小键盘等号

	{ VK_RETURN,       RL_E_KEY_KP_ENTER },   // 小键盘 Enter（Win 区分不明显）

	// -------- Android keys --------
	// Windows 无对应 VK，可自行扩展:
	// KEY_BACK = 4
	// KEY_MENU = 5
	// KEY_VOLUME_UP / DOWN 也无 VK 定义
};

int WinKey2RayKey(UINT winKey) {
	if (VK_TO_RAYLIB.count(winKey)) {
		return VK_TO_RAYLIB.at(winKey);
	}
	return winKey;
}

RLColor ParseColor(string sclr)
{
	if (sclr.empty())
		return WHITE;

	if (sclr[0] == '#')	// hex
	{
		/*if (sclr.size() < 7)
			return WHITE;*/

		auto [R, G, B, A] = HexToRGBA(sclr);
		return RAYRGBA(R, G, B, A);
	}
	if (sclr[0] == '&')
	{
		sclr = strxhead(sclr);
		char ch = sclr[0];
		if (isupper(ch)) ch = tolower(ch);
		UINT color16 = isalpha(ch) ? 10 + ch - 'a' : ch - '0';
		return Color16ToRGB(color16);
	}

	sclr = _strlwr((char*)sclr.c_str());
	if (sclr == "rainbow") {
		return RainbowColor(0.0f, g.rainbow_speed);
	}
	if (color_prefabs.find(sclr) != color_prefabs.end())
	{
		return RAYRGB(get<0>(color_prefabs[sclr]), get<1>(color_prefabs[sclr]), get<2>(color_prefabs[sclr]));
	}

	int r, G, b, a{ 255 };
	vector<string> cut = CutLine(sclr, ';');

	if (cut.size() == 1) {
		r = GetRValue(atoi(cut[0].c_str()));
		G = GetGValue(atoi(cut[0].c_str()));
		b = GetBValue(atoi(cut[0].c_str()));
		return RAYRGB(r, G, b);
	}
	else if (cut.size() == 3)
	{
		r = atoi(cut[0].c_str());
		G = atoi(cut[1].c_str());
		b = atoi(cut[2].c_str());
		return RAYRGB(r, G, b);
	}
	else if (cut.size() == 4)
	{
		r = atoi(cut[0].c_str());
		G = atoi(cut[1].c_str());
		b = atoi(cut[2].c_str());
		a = atoi(cut[3].c_str());
		return RAYRGBA(r, G, b, a);
	}
	return WHITE;
}

int DrawMixedString(int x, int y, const string& format,
	float imgScale, RLColor imgTint, bool textFlow = false, bool imgFlow = false, 
	bool textGlow = false, 
	RLColor glowColor = RLColorAlpha(WHITE, 0.2f), float glowRadius = g_fs * 0.05f,
	bool textShadow = true)
{
	RLColor textColor = g_fore_color;
	vector<string> chars;
	try {
		chars = CutCharacters(format);
	}
	catch (exception& e) {
		string format2{ format };
		ANSI2UTF8(format2);
		chars = CutCharacters(format2);
	}

	int cursorX = x;
	int baselineY = y + g_fs / 2;

	string textToken;
	string imgToken;
	bool readingImg = false;

	for (int i = 0; i < chars.size(); ++i) {
		const string& c = chars[i];

		if (!readingImg) {
			if (c == "{") {
				// 绘制之前累计的文本
				if (!textToken.empty()) {
					setcolor(g_fore_color);
					if (textGlow) {
						if (textFlow) {
							g.flow.Begin();
						}
						glowprint(cursorX, y, glowColor, glowRadius, textToken.c_str());
						if (textFlow) {
							g.flow.End();
						}
					}
					else if (textShadow) {
						RLColor oldColor = getcolor();
						setcolor(ColorAlpha2(BLACK, Clamp(oldColor.a / 255.0f * 0.78f, 0.0f, 1.0f)));
						flowprintf(cursorX + 2, y + 2, textFlow, 0.0f, "%s", textToken.c_str());
						setcolor(oldColor);
						flowprintf(cursorX, y, textFlow, 0.0f, "%s", textToken.c_str());
					}
					else {
						flowprintf(cursorX, y, textFlow, 0.0f, "%s", textToken.c_str());
					}
					cursorX += textwidth(textToken.c_str(), g_fs, g_spacing);
					textToken.clear();
				}

				readingImg = true;
				imgToken.clear();
				continue;
			}

			textToken += c;
		}
		else {
			if (c == "}") {
				readingImg = false;

				// 绘制图片
				if (sequ(imgToken, "loading")) {
					float r = g_fs / 2 * imgScale;
					float thick = Clamp(r / 6.0f, 1.0f, 50.0f);
					if (textShadow) {
						DrawLoadingAnimation(cursorX + r + 2.0f, baselineY + 2.0f, r,
							ColorAlpha2(BLACK, imgTint.a / 255.0f * 0.5f),
							ColorAlpha2(BLACK, imgTint.a / 255.0f * 0.5f), thick, 2000L, 0.1f);
					}
					if (imgFlow) {
						g.flow.SetDynamicColor(0.5f);
						g.flow.Begin();
					}
					DrawLoadingAnimation(cursorX + r, baselineY, r, imgTint, imgTint, thick, 2000L, 0.1f);
					if (imgFlow) {
						g.flow.End();
					}
					cursorX += r * 2 + g_fs / 4;
				}
				else if (g.textures.count(imgToken)) {
					RLTexture tex = g.textures[imgToken];
					float imgW = tex.width * imgScale;
					float imgH = tex.height * imgScale;

					int drawY = baselineY - imgH / 2;

					if (imgFlow) {
						g.flow.SetDynamicColor(0.5f);
						g.flow.Begin();
					}

					if (textShadow) {
						RLDrawTextureEx(tex, { (float)cursorX + 2.0f, (float)drawY + 2.0f },
							0.0f, imgScale, ColorAlpha2(BLACK, imgTint.a / 255.0f * 0.5f));
					}
					RLDrawTextureEx(tex, { (float)cursorX, (float)drawY },
						0.0f, imgScale, imgTint);

					if (imgFlow) {
						g.flow.End();
					}

					cursorX += imgW + g_fs / 4;
				}
				else {
					// 防止吞掉 {text}
					textToken += "{" + imgToken + "}";
				}
				continue;
			}

			imgToken += c;
		}
	}

	// 末尾还有文本
	if (!textToken.empty()) {
		setcolor(g_fore_color);
		if (textGlow) {
			if (textFlow) {
				g.flow.Begin();
			}
			glowprint(cursorX, y, glowColor, glowRadius, textToken.c_str());
			if (textFlow) {
				g.flow.End();
			}
		}
		else if (textShadow) {
			RLColor oldColor = getcolor();
			setcolor(ColorAlpha2(BLACK, Clamp(oldColor.a / 255.0f * 0.78f, 0.0f, 1.0f)));
			flowprintf(cursorX + 2, y + 2, textFlow, 0.0f, "%s", textToken.c_str());
			setcolor(oldColor);
			flowprintf(cursorX, y, textFlow, 0.0f, "%s", textToken.c_str());
		}
		else {
			flowprintf(cursorX, y, textFlow, 0.0f, "%s", textToken.c_str());
		}
		cursorX += textwidth(textToken.c_str(), g_fs, g_spacing);
	}

	// 返回总宽度
	return cursorX - x;
}


void DrawLoadingAnimation(
	float centerX,
	float centerY,
	float radius,
	RLColor color1,
	RLColor color2,
	float thickness,
	clock_t periodMs /*= 4000L*/,
	float phase0/* = 0.0f*/)
{
	// 归一化时间 0~1
	float t = (float)(clock() % periodMs) / (float)periodMs;
	t = fmodf(t + phase0, 1.0f);

	// ===== 1. 颜色 =====
	RLColor color = SinColor(color1, color2, periodMs, phase0);

	// ===== 2. 整体旋转角度 =====
	float baseAngle = t * 360.0f;

	// ===== 3. 弧长变化（追及问题的关键） =====
	float s = (sinf(t * 2.0f * PI) + 1.0f) * 0.5f;  // 0~1

	float minLen = 30.0f;   // 最短弧长（度）
	float maxLen = 270.0f;  // 最长弧长（度）

	float arcLen = minLen + (maxLen - minLen) * s;

	float startAngle = baseAngle;
	float endAngle = baseAngle + arcLen;

	// ===== 4. 绘制实心圆弧 =====
	RLDrawRing(
		{ centerX, centerY },
		radius - thickness,
		radius,
		startAngle,
		endAngle,
		64,          // 分段数，越大越圆
		color
	);
}

static RLColor ConsoleAttrToColor(WORD attr)
{
	bool intense = attr & FOREGROUND_INTENSITY;

	if (attr & FOREGROUND_RED && attr & FOREGROUND_GREEN && attr & FOREGROUND_BLUE)
		return intense ? RAYWHITE : GRAY;
	if (attr & FOREGROUND_RED && attr & FOREGROUND_GREEN)
		return intense ? YELLOW : GOLD;
	if (attr & FOREGROUND_RED && attr & FOREGROUND_BLUE)
		return intense ? MAGENTA : PURPLE;
	if (attr & FOREGROUND_GREEN && attr & FOREGROUND_BLUE)
		return intense ? SKYBLUE : BLUE;
	if (attr & FOREGROUND_RED)
		return intense ? RED : MAROON;
	if (attr & FOREGROUND_GREEN)
		return intense ? LIME : DARKGREEN;
	if (attr & FOREGROUND_BLUE)
		return intense ? BLUE : DARKBLUE;

	return intense ? LIGHTGRAY : DARKGRAY;
}

static RLRectangle LerpRect(const RLRectangle& a, const RLRectangle& b, float t)
{
	return {
		(float)Lerp<float>(a.x, b.x, t),
		(float)Lerp<float>(a.y, b.y, t),
		(float)Lerp<float>(a.width,  b.width,  t),
		(float)Lerp<float>(a.height, b.height, t)
	};
}
RLImage IconToImage(HICON hIcon, int size = 16)
{
	// 1. 使用真实设备 DC
	HDC hdc = GetDC(nullptr);
	HDC hMemDC = CreateCompatibleDC(hdc);

	// 2. 创建设备相关位图（关键！）
	HBITMAP hBitmap = CreateCompatibleBitmap(hdc, size, size);
	HBITMAP oldBmp = (HBITMAP)SelectObject(hMemDC, hBitmap);

	// 3. 清空为透明（黑底无所谓，Alpha 会重算）
	RECT rc{ 0, 0, size, size };
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
	FillRect(hMemDC, &rc, hBrush);
	DeleteObject(hBrush);

	// 4. 让 Windows 正确绘制图标（Explorer 同款）
	DrawIconEx(
		hMemDC,
		0, 0,
		hIcon,
		size, size,
		0,
		nullptr,
		DI_NORMAL
	);

	// 5. 用 GetDIBits 拿最终像素
	BYTE* pixels = new BYTE[size * size * 4];

	BITMAPINFO bmi{};
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = size;
	bmi.bmiHeader.biHeight = -size; // top-down
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;

	GetDIBits(
		hMemDC,
		hBitmap,
		0,
		size,
		pixels,
		&bmi,
		DIB_RGB_COLORS
	);

	// 6. 转成 raylib Image（沿用你截图函数的做法）
	RLImage img = RLGenImageColor(size, size, BLANK);

	for (int y = 0; y < size; ++y)
		for (int x = 0; x < size; ++x) {
			int i = (y * size + x) * 4;
			RLImageDrawPixel(
				&img,
				x,
				y,
				RAYRGBA(
					pixels[i + 2], // R
					pixels[i + 1], // G
					pixels[i + 0], // B
					255             // Alpha：GDI 已经合成
				)
			);
		}

	// 7. 清理
	delete[] pixels;
	SelectObject(hMemDC, oldBmp);
	DeleteObject(hBitmap);
	DeleteDC(hMemDC);
	ReleaseDC(nullptr, hdc);
	DestroyIcon(hIcon);

	return img;
}

string RecognizeColor(RLColor c)
{
	// ---------- 透明 ----------
	if (c.a < 15)
		return "Transparent";

	auto [h, s, v] = RLColorToHSV(c);

	// ---------- 黑白灰 ----------
	if (v < 0.08f) return "Black";

	if (s < 0.12f) {
		if (v > 0.92f) return "White";
		if (v > 0.7f)  return "LightGray";
		if (v > 0.35f) return "Gray";
		return "DarkGray";
	}

	// ---------- 棕色特判 ----------
	if (h >= 15 && h <= 45 && v < 0.6f)
		return "Brown";

	// ---------- 基础色 ----------
	string base;

	if (h < 10 || h >= 350)       base = "Red";
	else if (h < 25)              base = "Orange";
	else if (h < 45)              base = "Yellow";
	else if (h < 65)              base = "Lime";
	else if (h < 145)             base = "Green";
	else if (h < 170)             base = "Teal";
	else if (h < 195)             base = "Cyan";
	else if (h < 215)             base = "SkyBlue";
	else if (h < 240)             base = "Blue";
	else if (h < 260)             base = "Indigo";
	else if (h < 290)             base = "Purple";
	else                          base = "Magenta";

	// ---------- 修饰词 ----------
	string prefix;

	if (s > 0.85f && v > 0.75f)
		prefix = "Neon ";
	else if (v < 0.35f)
		prefix = "Dark ";
	else if (v > 0.8f)
		prefix = "Light ";
	else if (s < 0.35f)
		prefix = "Pale ";

	return prefix + base;
}

// sRGB -> Linear (近似 gamma 2.2)
static inline float SrgbToLinear(float x)
{
	// x in [0,1]
	return powf(x, 2.2f);
}

// Linear -> sRGB
static inline float LinearToSrgb(float x)
{
	x = std::clamp(x, 0.0f, 1.0f);
	return powf(x, 1.0f / 2.2f);
}

// 返回“马赛克到最大程度”的代表色（整图平均色）
// sampleTarget: 希望抽样的像素总数目标，越大越准但越慢（如 4096 或 8192）
// ignoreAlphaBelow: alpha 小于此阈值的像素直接忽略（避免透明边缘污染）
RLColor GetImageMosaicColor(const RLImage& img, int sampleTarget = 4096, int ignoreAlphaBelow = 8)
{
	if (img.data == nullptr || img.width <= 0 || img.height <= 0) {
		return BLACK;
	}

	// raylib 提供的解码为 Color 数组（RGBA 8-bit）
	RLColor* pixels = RLLoadImageColors(img);
	if (!pixels) return BLACK;

	const int w = img.width;
	const int h = img.height;
	const int total = w * h;

	// 计算步长：让抽样点大约接近 sampleTarget
	// stride=1 表示全采样；stride 越大越快
	int stride = 1;
	if (sampleTarget > 0 && total > sampleTarget) {
		float ratio = std::sqrt((float)total / (float)sampleTarget);
		stride = (int)std::floor(ratio);
		stride = std::max(1, stride);
	}

	// 在线性空间累加
	double sumR = 0.0, sumG = 0.0, sumB = 0.0;
	double sumW = 0.0;

	// 也可以用规则网格采样（更稳定），这里用 stride 网格
	for (int y = 0; y < h; y += stride) {
		int row = y * w;
		for (int x = 0; x < w; x += stride) {
			RLColor c = pixels[row + x];

			if (c.a < ignoreAlphaBelow) continue;

			float a = c.a / 255.0f;          // alpha 权重
			float r = c.r / 255.0f;
			float g = c.g / 255.0f;
			float b = c.b / 255.0f;

			// sRGB -> Linear 后再平均（更像“光”在混合）
			float lr = SrgbToLinear(r);
			float lg = SrgbToLinear(g);
			float lb = SrgbToLinear(b);

			sumR += lr * a;
			sumG += lg * a;
			sumB += lb * a;
			sumW += a;
		}
	}

	RLUnloadImageColors(pixels);

	// 全透明/全被忽略：给个兜底
	if (sumW <= 1e-9) {
		return BLANK; // 或 BLACK，看你 UI 想要什么
	}

	float avgR = (float)(sumR / sumW);
	float avgG = (float)(sumG / sumW);
	float avgB = (float)(sumB / sumW);

	// Linear -> sRGB
	float sr = LinearToSrgb(avgR);
	float sg = LinearToSrgb(avgG);
	float sb = LinearToSrgb(avgB);

	RLColor out;
	out.r = (unsigned char)std::lround(std::clamp(sr, 0.0f, 1.0f) * 255.0f);
	out.g = (unsigned char)std::lround(std::clamp(sg, 0.0f, 1.0f) * 255.0f);
	out.b = (unsigned char)std::lround(std::clamp(sb, 0.0f, 1.0f) * 255.0f);
	out.a = 255;

	return out;
}

void OutputBiColorString(
	const string& text,
	RLColor color1,
	RLColor color2,
	size_t period,
	float phase
) {
	auto chars = CutCharacters(text);
	if (chars.empty())
		return;

	// 防止除 0
	if (period == 0)
		period = chars.size();

	// phase 归一化到 [0,1)
	phase = fmodf(phase, 1.0f);
	if (phase < 0.0f)
		phase += 1.0f;

	const float invPeriod = 1.0f / static_cast<float>(period);

	for (size_t i = 0; i < chars.size(); ++i) {
		/*float rate = fmodf(i * invPeriod + phase, 1.0f);

		auto c = StepColor(color1, color2, rate);*/

		float rate = Triangle(fmodf(i * invPeriod + phase, 1.0f));
		auto c = StepColor(color1, color2, rate);

		SetColor(c);
		cout << chars[i];
	}
}
RLVector2 WorldToScreen(
	RLVector2 world,
	RLVector2 cam,
	RLRectangle view
)
{
	return {
		view.x + view.width * 0.5f + (world.x - cam.x),
		view.y + view.height * 0.5f + (world.y - cam.y)
	};
}

static RLVector2 WarpUI_ScreenUV_To_SourceUV(
	RLVector2 screenUV,
	RLVector2 resolution,
	RLVector2 tilt,
	float camZ,
	float preScale)
{
	float aspect = resolution.x / resolution.y;

	RLVector2 ndc = {
		screenUV.x * 2.0f - 1.0f,
		screenUV.y * 2.0f - 1.0f
	};

	ndc.x *= aspect;
	ndc.x /= preScale;
	ndc.y /= preScale;

	RLVector3 ro = { 0, 0, camZ };
	RLVector3 rd = RLVector3Normalize({ ndc.x, ndc.y, -camZ });

	RLMatrix Rx = RLMatrixRotateX(tilt.x);
	RLMatrix Ry = RLMatrixRotateY(tilt.y);
	RLMatrix R = RLMatrixMultiply(Rx, Ry);

	RLVector3 n = RLVector3Transform({ 0, 0, 1 }, R);

	float denom = RLVector3DotProduct(rd, n);
	if (fabsf(denom) < 1e-6f) return { -1, -1 };

	float t = RLVector3DotProduct(RLVector3Negate(ro), n) / denom;
	if (t <= 0.0f) return { -1, -1 };

	RLVector3 hit = RLVector3Add(ro, RLVector3Scale(rd, t));
	RLVector3 local = RLVector3Transform(hit, RLMatrixTranspose(R));

	return {
		(local.x / aspect) * 0.5f + 0.5f,
		local.y * 0.5f + 0.5f
	};
}

static inline RLVector2 ProjectPlanePointToScreenUV(RLVector3 planeLocalXY0,
	RLVector2 resolution,
	RLVector2 tilt,
	float camZ,
	float preScale)
{
	float aspect = resolution.x / resolution.y;

	// 旋转
	RLMatrix Rx = RLMatrixRotateX(tilt.x);
	RLMatrix Ry = RLMatrixRotateY(tilt.y);
	RLMatrix R = RLMatrixMultiply(Rx, Ry);

	RLVector3 Pw = RLVector3Transform(planeLocalXY0, R); // world point on rotated plane

	// 相机在 (0,0,camZ)，把点 Pw 透视投影到屏幕平面 z=0
	// 线段 C->Pw 与 z=0 的交点
	// t = camZ / (camZ - Pw.z)
	float t = camZ / (camZ - Pw.z);
	float sx = Pw.x * t;
	float sy = Pw.y * t;

	// 归一化到 screenUV，注意 preScale（和 shader 一致：ndc /= preScale）
	sx /= preScale;
	sy /= preScale;

	RLVector2 uv;
	uv.x = (sx / aspect) * 0.5f + 0.5f;
	uv.y = (sy) * 0.5f + 0.5f;
	return uv;
}

// --- 求 Homography: srcUV -> screenUV ---
// 这里用 4 点直接解（8个未知量，h33=1），实现略长；你若已有线性方程求解器可直接套。
// 我给一个清晰接口：BuildH 和 InvertH
static Mat3 InvertMat3(const Mat3& A)
{
	const float* a = A.m;

	float det =
		a[0] * (a[4] * a[8] - a[5] * a[7]) -
		a[1] * (a[3] * a[8] - a[5] * a[6]) +
		a[2] * (a[3] * a[7] - a[4] * a[6]);

	Mat3 inv = {};

	if (fabsf(det) < 1e-8f)
		return inv; // 返回零矩阵，调用方应当做合法性判断

	float invDet = 1.0f / det;

	inv.m[0] = (a[4] * a[8] - a[5] * a[7]) * invDet;
	inv.m[1] = -(a[1] * a[8] - a[2] * a[7]) * invDet;
	inv.m[2] = (a[1] * a[5] - a[2] * a[4]) * invDet;

	inv.m[3] = -(a[3] * a[8] - a[5] * a[6]) * invDet;
	inv.m[4] = (a[0] * a[8] - a[2] * a[6]) * invDet;
	inv.m[5] = -(a[0] * a[5] - a[2] * a[3]) * invDet;

	inv.m[6] = (a[3] * a[7] - a[4] * a[6]) * invDet;
	inv.m[7] = -(a[0] * a[7] - a[1] * a[6]) * invDet;
	inv.m[8] = (a[0] * a[4] - a[1] * a[3]) * invDet;

	return inv;
}
static bool SolveLinear8(float A[8][8], float B[8], float X[8])
{
	// 高斯消元（带主元）
	for (int i = 0; i < 8; ++i)
	{
		int maxRow = i;
		for (int r = i + 1; r < 8; ++r)
			if (fabsf(A[r][i]) > fabsf(A[maxRow][i]))
				maxRow = r;

		if (fabsf(A[maxRow][i]) < 1e-8f)
			return false;

		if (maxRow != i)
		{
			for (int c = 0; c < 8; ++c)
				std::swap(A[i][c], A[maxRow][c]);
			std::swap(B[i], B[maxRow]);
		}

		float invPivot = 1.0f / A[i][i];
		for (int c = i; c < 8; ++c)
			A[i][c] *= invPivot;
		B[i] *= invPivot;

		for (int r = 0; r < 8; ++r)
		{
			if (r == i) continue;
			float f = A[r][i];
			for (int c = i; c < 8; ++c)
				A[r][c] -= f * A[i][c];
			B[r] -= f * B[i];
		}
	}

	for (int i = 0; i < 8; ++i)
		X[i] = B[i];

	return true;
}

static Mat3 BuildHomography_SrcToScreen(
	const RLVector2 src[4],
	const RLVector2 dst[4])
{
	float A[8][8] = {};
	float B[8] = {};

	for (int i = 0; i < 4; ++i)
	{
		float x = src[i].x;
		float y = src[i].y;
		float u = dst[i].x;
		float v = dst[i].y;

		int r = i * 2;

		// u = (h11 x + h12 y + h13) / (h31 x + h32 y + 1)
		A[r][0] = x;  A[r][1] = y;  A[r][2] = 1;
		A[r][6] = -u * x;
		A[r][7] = -u * y;
		B[r] = u;

		// v = (h21 x + h22 y + h23) / (h31 x + h32 y + 1)
		A[r + 1][3] = x;  A[r + 1][4] = y;  A[r + 1][5] = 1;
		A[r + 1][6] = -v * x;
		A[r + 1][7] = -v * y;
		B[r + 1] = v;
	}

	float X[8];
	SolveLinear8(A, B, X);

	Mat3 H = {};
	H.m[0] = X[0]; H.m[1] = X[1]; H.m[2] = X[2];
	H.m[3] = X[3]; H.m[4] = X[4]; H.m[5] = X[5];
	H.m[6] = X[6]; H.m[7] = X[7]; H.m[8] = 1.0f;

	return H;
}


static Mat3 BuildHinv_WarpUI(RLVector2 resolution, RLVector2 tilt, float camZ, float preScale)
{
	// src UV corners
	RLVector2 src[4] = {
		{0,0}, {1,0}, {1,1}, {0,1}
	};

	float aspect = resolution.x / resolution.y;
	// plane local corners (z=0) with aspect in x
	RLVector3 p00 = { -aspect, -1.0f, 0.0f };
	RLVector3 p10 = { aspect, -1.0f, 0.0f };
	RLVector3 p11 = { aspect,  1.0f, 0.0f };
	RLVector3 p01 = { -aspect,  1.0f, 0.0f };

	RLVector2 dst[4] = {
		ProjectPlanePointToScreenUV(p00, resolution, tilt, camZ, preScale),
		ProjectPlanePointToScreenUV(p10, resolution, tilt, camZ, preScale),
		ProjectPlanePointToScreenUV(p11, resolution, tilt, camZ, preScale),
		ProjectPlanePointToScreenUV(p01, resolution, tilt, camZ, preScale),
	};

	// ==============================
	// ⭐ 关键修复：补偿 DrawTexturePro 的 -height
	// ==============================
	for (int i = 0; i < 4; ++i)
	{
		dst[i].y = 1.0f - dst[i].y;
	}

	Mat3 H = BuildHomography_SrcToScreen(src, dst);
	Mat3 Hinv = InvertMat3(H);
	return Hinv;
}

// 用 Hinv 把 screenUV -> srcUV
static inline RLVector2 ApplyHinv(const Mat3& Hinv, RLVector2 uv)
{
	float x = uv.x, y = uv.y;
	float X = Hinv.m[0] * x + Hinv.m[1] * y + Hinv.m[2];
	float Y = Hinv.m[3] * x + Hinv.m[4] * y + Hinv.m[5];
	float W = Hinv.m[6] * x + Hinv.m[7] * y + Hinv.m[8];
	if (fabsf(W) < 1e-6f) return { -1,-1 };
	return { X / W, Y / W };
}

static void BuildCameraRay(
	RLVector2 screenUV,
	RLVector2 resolution,
	float camZ,
	RLVector2 camOffset,
	float camYaw,
	float camPitch,
	float camRoll,
	float fov,
	RLVector3& outRo,
	RLVector3& outRd)
{
	// ------------------------------
	// ScreenUV -> NDC (-1..1)
	// ------------------------------
	float aspect = resolution.x / resolution.y;

	RLVector2 ndc = {
		screenUV.x * 2.0f - 1.0f,
		screenUV.y * 2.0f - 1.0f
	};

	// ------------------------------
	// Perspective projection plane (FOV-based)
	// ------------------------------
	float tanHalfFov = tanf(fov * 0.5f);

	RLVector2 plane = {
		ndc.x * aspect * tanHalfFov,
		ndc.y * tanHalfFov
	};

	// ------------------------------
	// Camera origin (world space)
	// ------------------------------
	outRo = {
		camOffset.x,
		camOffset.y,
		camZ
	};

	// ------------------------------
	// Ray direction (camera space)
	// ------------------------------
	RLVector3 rd = {
		plane.x,
		plane.y,
		-1.0f            // ⭐ 标准 pinhole camera
	};
	rd = RLVector3Normalize(rd);

	// ------------------------------
	// Camera rotation (MUST match shader)
	// Shader: rotY(camYaw) * rotX(camPitch) * rotZ(camRoll) * rd
	// 这里显式按同顺序逐步旋转，避免矩阵布局差异导致交互角度偏差。
	// ------------------------------
	auto rotZ = [](RLVector3 v, float a) {
		float s = sinf(a), c = cosf(a);
		return RLVector3{ v.x * c - v.y * s, v.x * s + v.y * c, v.z };
	};
	auto rotX = [](RLVector3 v, float a) {
		float s = sinf(a), c = cosf(a);
		return RLVector3{ v.x, v.y * c - v.z * s, v.y * s + v.z * c };
	};
	auto rotY = [](RLVector3 v, float a) {
		float s = sinf(a), c = cosf(a);
		return RLVector3{ v.x * c + v.z * s, v.y, -v.x * s + v.z * c };
	};

	rd = rotZ(rd, camRoll);
	rd = rotX(rd, camPitch);
	rd = rotY(rd, camYaw);
	outRd = RLVector3Normalize(rd);
}

//static Vector2 RayPlane_To_UV(
//	Vector2 screenUV,
//	Vector2 resolution,
//	Vector2 tilt,
//	float camZ,
//	Vector2 camOffset,
//	float camYaw,
//	float camPitch,
//	float camRoll,
//	float preScale)
//{
//	float aspect = resolution.x / resolution.y;
//
//	// Build camera ray (same as shader)
//	Vector3 ro, rd;
//	BuildCameraRay(
//		screenUV, resolution,
//		camZ, camOffset, camYaw, camPitch, camRoll,
//		preScale,
//		ro, rd
//	);
//
//	// Plane rotation (tilt) - same order as shader: rotX * rotY
//	Matrix Rx = MatrixRotateX(tilt.x);
//	Matrix Ry = MatrixRotateY(tilt.y);
//	Matrix Rplane = MatrixMultiply(Rx, Ry);
//
//	// Plane normal in world
//	Vector3 n = Vector3Transform({ 0, 0, 1 }, Rplane);
//
//	float denom = Vector3DotProduct(rd, n);
//	if (fabsf(denom) < 1e-6f)
//		return { -1.0f, -1.0f };
//
//	// Plane passes through origin
//	float t = Vector3DotProduct(Vector3Negate(ro), n) / denom;
//	if (t <= 0.0f)
//		return { -1.0f, -1.0f };
//
//	Vector3 hit = Vector3Add(ro, Vector3Scale(rd, t));
//
//	// Back to plane local space
//	Vector3 local = Vector3Transform(hit, MatrixTranspose(Rplane));
//
//	// Local -> UV (same as shader)
//	Vector2 uv;
//	uv.x = (local.x / aspect) * 0.5f + 0.5f;
//	uv.y = local.y * 0.5f + 0.5f;
//	return uv;
//}
static RLVector2 RayPlane_To_UV(
	RLVector2 screenUV,
	RLVector2 resolution,
	float camZ,
	RLVector2 camOffset,
	float camYaw,
	float camPitch,
	float camRoll,
	float fov)
{
	float aspect = resolution.x / resolution.y;

	// Build camera ray (same as shader)
	RLVector3 ro, rd;
	BuildCameraRay(
		screenUV,
		resolution,
		camZ,
		camOffset,
		camYaw,
		camPitch,
		camRoll,     // ⭐ 新增
		fov,
		ro,
		rd
	);

	// Plane is fixed: z = 0
	if (fabsf(rd.z) < 1e-6f)
		return { -1.0f, -1.0f };

	float t = -ro.z / rd.z;
	if (t <= 0.0f)
		return { -1.0f, -1.0f };

	RLVector3 hit = RLVector3Add(ro, RLVector3Scale(rd, t));

	// World hit → Plane local (identity, no rotation)
	RLVector2 uv;
	uv.x = (hit.x / aspect) * 0.5f + 0.5f;
	uv.y = hit.y * 0.5f + 0.5f;
	return uv;
}


static RLVector2 RaySphere_To_UV(
	RLVector2 screenUV,
	RLVector2 resolution,
	float camZ,
	RLVector2 camOffset,
	float camYaw,
	float camPitch,
	float camRoll,
	float fov,
	float sphereRadius,
	bool insideSurface)
{
	float aspect = resolution.x / resolution.y;

	RLVector3 ro, rd;
	BuildCameraRay(
		screenUV,
		resolution,
		camZ,
		camOffset,
		camYaw,
		camPitch,
		camRoll,
		fov,
		ro,
		rd
	);

	// Curved surface: tangent sphere behind plane
	float R = sphereRadius;
	if (R <= 1e-6f)
		return { -1.0f, -1.0f };

	RLVector3 C = { 0.0f, 0.0f, insideSurface ? R : -R };
	RLVector3 oc = RLVector3Subtract(ro, C);

	float b = RLVector3DotProduct(oc, rd);
	float c = RLVector3DotProduct(oc, oc) - R * R;
	float h = b * b - c;

	if (h < 0.0f)
		return { -1.0f, -1.0f };

	// Choose which surface to sample
	float t = -b - sqrtf(h);
	if (t <= 0.0f) t = -b + sqrtf(h);
	if (t <= 0.0f)
		return { -1.0f, -1.0f };

	RLVector3 hit = RLVector3Add(ro, RLVector3Scale(rd, t));

	// Curved surface UV (no wrap seam)
	RLVector3 v = RLVector3Subtract(hit, C);
	if (insideSurface) v.z = -v.z;
	float angleX = atan2f(v.x, v.z);
	float angleY = atan2f(v.y, v.z);
	float tanHalfFov = tanf(fov * 0.5f);
	float halfW = aspect * tanHalfFov;
	float halfH = tanHalfFov;
	RLVector2 uv;
	uv.x = (R * angleX) / (2.0f * halfW) + 0.5f;
	uv.y = (R * angleY) / (2.0f * halfH) + 0.5f;
	return uv;
}
