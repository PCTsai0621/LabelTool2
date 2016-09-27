#pragma once
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "mat.h"

#define LOG 0
#define LABEL 1
#define picWidthScale 2
#define picHeightScale 2
#define FEILD1 1
#define FEILD2 2

CvCapture* capture;	
IplImage* frame;
int frame_count;
int video_status_flag = 0;
int video_load_flag = 0;
int edit_mode_label = 0;
int edit_mode_modify = 0;
int draw_flag = 0;

MATFile *pmat;

char *SourceName;

/*data structure for label mat file*/
int result_label;
char *label_file = "MOMO_more.mat";
const char *label_parameterName = "labels";
const char *label_field1 = "ptsAll";
const char *label_field2 = "segmentTypes";

/*data structure for log mat file*/
int result_log;
char *log_file = "grab_log.mat";
const char *log_parameterName = "grab_log";
const char *log_field1 = "grab_order";
const char *log_field2 = "inputSource";



int result_inputVideo;

/*variable for reading label struct array*/
double *mxData_label;
int nDim_label;
const mwSize *dims_label;
int row_label, col_label, z_label;
mxClassID classid_label;

/*variable for reading log struct array in field1*/
double *mxData_log;
int nDim_log1;
const mwSize *dims_log1;
int row_log1, col_log1, z_log1;
mxClassID classid_log1;

/*variable for reading log struct array in field2*/
mxChar* mxData_log_video;
int nDim_log2;
const mwSize *dims_log2;
int row_log2, col_log2, z_log2;
mxClassID classid_log2;

///*analyzestructarray variable*/
//mwSize nElements;       /* number of elements in array */
//mwIndex eIdx;           /* element index */
//const mxArray *fPtr;    /* field pointer */
//double *realPtr;        /* pointer to data */
//double total;           /* value to calculate */
//
//int nDim;
//const mwSize *dims;
//int row, col, z;
//mxClassID classid;

namespace LabelTool2{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//

			label_picBox1_W_context->Text = pictureBox1->Width.ToString();
			label_picBox1_H_context->Text = pictureBox1->Height.ToString();
			label_picBox2_W_context->Text = pictureBox2->Width.ToString();
			label_picBox2_H_context->Text = pictureBox2->Height.ToString();

			g = pictureBox2->CreateGraphics();
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::TrackBar^  trackBar1;


	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  btn_play;
	private: System::Windows::Forms::Button^  btn_pause;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Panel^  panel_path;

	private: System::Windows::Forms::Label^  lab_path_context;
	private: System::Windows::Forms::Label^  lab_path;
	private: System::Windows::Forms::Panel^  panel_frame;

	private: System::Windows::Forms::Label^  lab_frame;
	private: System::Windows::Forms::Label^  lab_frame_context;




	private: System::Windows::Forms::Panel^  panel_frame_count;
	private: System::Windows::Forms::Label^  lab_frame_count;


	private: System::Windows::Forms::Label^  lab_frame_count_context;

	




	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Button^  btn_jump_to;
	private: System::Windows::Forms::TextBox^  textBox_jump_to;
	private: System::Windows::Forms::Button^  btn_preview_mode;
	private: System::Windows::Forms::Button^  btn_edit_mode;

	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Button^  btn_edit_modify;

	private: System::Windows::Forms::Button^  btn_edit_label;






	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		array<double, 3>^ label_array;
		Graphics^ g ;
		int index;
		String^ SelectedFolder;
		System::IO::File^ filelist;
		int result_load;
		int flag_edit_label, flag_edit_modify;
		//array<double, 2>^ log_order_array;

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  lab_label_x_context;
	private: System::Windows::Forms::Label^  lab_label_x;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  lab_label_y_context;
	private: System::Windows::Forms::Label^  lab_label_y;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  lab_frame_height;
	private: System::Windows::Forms::Label^  lab_frame_height_context;


	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  lab_frame_width;
	private: System::Windows::Forms::Label^  lab_frame_width_context;
	private: System::Windows::Forms::Button^  btn_clean_mat;
	private: System::Windows::Forms::Button^  btn_load_mat;
	private: System::Windows::Forms::Panel^  panel5;
private: System::Windows::Forms::Label^  label_picBox1_W;
private: System::Windows::Forms::Label^  label_picBox1_W_context;





private: System::Windows::Forms::PictureBox^  pictureBox2;
private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::Panel^  panel6;
private: System::Windows::Forms::Label^  label_picBox1_H;
private: System::Windows::Forms::Label^  label_picBox1_H_context;




private: System::Windows::Forms::Panel^  panel7;
private: System::Windows::Forms::Label^  label_picBox2_W;
private: System::Windows::Forms::Label^  label_picBox2_W_context;




private: System::Windows::Forms::Panel^  panel8;
private: System::Windows::Forms::Label^  label_picBox2_H;
private: System::Windows::Forms::Label^  label_picBox2_H_context;


private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::Panel^  panel15;
private: System::Windows::Forms::Label^  label_Width_Scale;
private: System::Windows::Forms::Label^  label_Width_Scale_context;


private: System::Windows::Forms::Panel^  panel12;
private: System::Windows::Forms::Label^  label_log_D2;
private: System::Windows::Forms::Label^  label_log_D2_context;


private: System::Windows::Forms::Panel^  panel11;
private: System::Windows::Forms::Label^  label_label_D2;
private: System::Windows::Forms::Label^  label_label_D2_context;


private: System::Windows::Forms::Panel^  panel13;
private: System::Windows::Forms::Label^  label_log_D1;
private: System::Windows::Forms::Label^  label_log_D1_context;


private: System::Windows::Forms::Panel^  panel10;
private: System::Windows::Forms::Label^  label_label_D1;
private: System::Windows::Forms::Label^  label_label_D1_context;


private: System::Windows::Forms::Panel^  panel14;
private: System::Windows::Forms::Label^  label_log_D0;
private: System::Windows::Forms::Label^  label_log_D0_context;


private: System::Windows::Forms::Panel^  panel9;
private: System::Windows::Forms::Label^  label_label_D0;
private: System::Windows::Forms::Label^  label_label_D0_context;


private: System::Windows::Forms::Panel^  panel16;
private: System::Windows::Forms::Label^  label_Height_Scale;
private: System::Windows::Forms::Label^  label_Height_Scale_context;
private: System::Windows::Forms::Button^  btn_DEBUG_refresh;
private: System::Windows::Forms::Panel^  panel17;
private: System::Windows::Forms::Label^  label_ListBox_Index;
private: System::Windows::Forms::Label^  label_ListBox_Index_context;
private: System::Windows::Forms::Panel^  panel18;
private: System::Windows::Forms::Label^  label_picBox2_ImgH;
private: System::Windows::Forms::Label^  label_picBox2_ImgH_context;

private: System::Windows::Forms::Panel^  panel19;
private: System::Windows::Forms::Label^  label_picBox2_ImgW;
private: System::Windows::Forms::Label^  label_picBox2_ImgW_context;
private: System::Windows::Forms::Panel^  panel21;
private: System::Windows::Forms::Label^  label_result_log;
private: System::Windows::Forms::Label^  label_result_log_context;
private: System::Windows::Forms::Panel^  panel20;
private: System::Windows::Forms::Label^  label_result_label;
private: System::Windows::Forms::Label^  label_result_label_context;
private: System::Windows::Forms::Panel^  panel27;
private: System::Windows::Forms::Label^  label_label_P10_context;
private: System::Windows::Forms::Label^  label_label_P10;
private: System::Windows::Forms::Panel^  panel33;
private: System::Windows::Forms::Label^  label_label_P14_context;
private: System::Windows::Forms::Label^  label_label_P14;
private: System::Windows::Forms::Panel^  panel26;
private: System::Windows::Forms::Label^  label_label_P5_context;
private: System::Windows::Forms::Label^  label_label_P5;
private: System::Windows::Forms::Panel^  panel34;
private: System::Windows::Forms::Label^  label_label_P13_context;
private: System::Windows::Forms::Label^  label_label_P13;
private: System::Windows::Forms::Panel^  panel28;
private: System::Windows::Forms::Label^  label_label_P9_context;
private: System::Windows::Forms::Label^  label_label_P9;
private: System::Windows::Forms::Panel^  panel35;
private: System::Windows::Forms::Label^  label_label_P12_context;
private: System::Windows::Forms::Label^  label_label_P12;
private: System::Windows::Forms::Panel^  panel25;
private: System::Windows::Forms::Label^  label_label_P4_context;
private: System::Windows::Forms::Label^  label_label_P4;
private: System::Windows::Forms::Panel^  panel36;
private: System::Windows::Forms::Label^  label_label_P11_context;
private: System::Windows::Forms::Label^  label_label_P11;
private: System::Windows::Forms::Panel^  panel29;
private: System::Windows::Forms::Label^  label_label_P8_context;
private: System::Windows::Forms::Label^  label_label_P8;
private: System::Windows::Forms::Panel^  panel24;
private: System::Windows::Forms::Label^  label_label_P3_context;
private: System::Windows::Forms::Label^  label_label_P3;
private: System::Windows::Forms::Panel^  panel30;
private: System::Windows::Forms::Label^  label_label_P7_context;
private: System::Windows::Forms::Label^  label_label_P7;
private: System::Windows::Forms::Panel^  panel23;
private: System::Windows::Forms::Label^  label_label_P2_context;
private: System::Windows::Forms::Label^  label_label_P2;
private: System::Windows::Forms::Panel^  panel31;
private: System::Windows::Forms::Label^  label_label_P6_context;
private: System::Windows::Forms::Label^  label_label_P6;
private: System::Windows::Forms::Panel^  panel22;
private: System::Windows::Forms::Label^  label_label_P1_context;
private: System::Windows::Forms::Label^  label_label_P1;
private: System::Windows::Forms::CheckBox^  chkBox_skeletonize_state;
private: System::Windows::Forms::Panel^  panel38;
private: System::Windows::Forms::Label^  label_Print_Coord_Y;
private: System::Windows::Forms::Label^  label_Print_Coord_Y_context;
private: System::Windows::Forms::Panel^  panel39;
private: System::Windows::Forms::Label^  label_Print_Coord_X;
private: System::Windows::Forms::Label^  label_Print_Coord_X_context;
private: System::Windows::Forms::Panel^  panel32;
private: System::Windows::Forms::Label^  label_Read_Coord_Y;
private: System::Windows::Forms::Label^  label_Read_Coord_Y_context;
private: System::Windows::Forms::Panel^  panel37;
private: System::Windows::Forms::Label^  label_Read_Coord_X;
private: System::Windows::Forms::Label^  label_Read_Coord_X_context;
private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
private: System::Windows::Forms::Panel^  panel41;
private: System::Windows::Forms::Label^  label_log_matfile_context;

private: System::Windows::Forms::Label^  label_log_matfile;
private: System::Windows::Forms::Panel^  panel40;
private: System::Windows::Forms::Label^  label_label_matfile_context;
private: System::Windows::Forms::Label^  label_label_matfile;
private: System::Windows::Forms::Panel^  panel42;
private: System::Windows::Forms::Label^  label_selected_folder;
private: System::Windows::Forms::Label^  label_selected_folder_context;
private: System::Windows::Forms::Panel^  panel43;
private: System::Windows::Forms::Label^  label_result_log2;
private: System::Windows::Forms::Panel^  panel44;
private: System::Windows::Forms::Label^  label_match_point;
private: System::Windows::Forms::Label^  label_match_point_context;
private: System::Windows::Forms::Label^  label_result_log2_context;







#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btn_play = (gcnew System::Windows::Forms::Button());
			this->btn_pause = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->lab_frame_height = (gcnew System::Windows::Forms::Label());
			this->lab_frame_height_context = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->lab_frame_width = (gcnew System::Windows::Forms::Label());
			this->lab_frame_width_context = (gcnew System::Windows::Forms::Label());
			this->btn_jump_to = (gcnew System::Windows::Forms::Button());
			this->textBox_jump_to = (gcnew System::Windows::Forms::TextBox());
			this->panel_frame_count = (gcnew System::Windows::Forms::Panel());
			this->lab_frame_count = (gcnew System::Windows::Forms::Label());
			this->lab_frame_count_context = (gcnew System::Windows::Forms::Label());
			this->panel_frame = (gcnew System::Windows::Forms::Panel());
			this->lab_frame = (gcnew System::Windows::Forms::Label());
			this->lab_frame_context = (gcnew System::Windows::Forms::Label());
			this->panel_path = (gcnew System::Windows::Forms::Panel());
			this->lab_path_context = (gcnew System::Windows::Forms::Label());
			this->lab_path = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->panel41 = (gcnew System::Windows::Forms::Panel());
			this->label_log_matfile_context = (gcnew System::Windows::Forms::Label());
			this->label_log_matfile = (gcnew System::Windows::Forms::Label());
			this->panel40 = (gcnew System::Windows::Forms::Panel());
			this->label_label_matfile_context = (gcnew System::Windows::Forms::Label());
			this->label_label_matfile = (gcnew System::Windows::Forms::Label());
			this->btn_preview_mode = (gcnew System::Windows::Forms::Button());
			this->btn_edit_mode = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->chkBox_skeletonize_state = (gcnew System::Windows::Forms::CheckBox());
			this->btn_clean_mat = (gcnew System::Windows::Forms::Button());
			this->btn_load_mat = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->lab_label_x_context = (gcnew System::Windows::Forms::Label());
			this->lab_label_x = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lab_label_y_context = (gcnew System::Windows::Forms::Label());
			this->lab_label_y = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->btn_edit_modify = (gcnew System::Windows::Forms::Button());
			this->btn_edit_label = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label_picBox1_W = (gcnew System::Windows::Forms::Label());
			this->label_picBox1_W_context = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->panel27 = (gcnew System::Windows::Forms::Panel());
			this->label_label_P10_context = (gcnew System::Windows::Forms::Label());
			this->label_label_P10 = (gcnew System::Windows::Forms::Label());
			this->panel33 = (gcnew System::Windows::Forms::Panel());
			this->label_label_P14_context = (gcnew System::Windows::Forms::Label());
			this->label_label_P14 = (gcnew System::Windows::Forms::Label());
			this->panel26 = (gcnew System::Windows::Forms::Panel());
			this->label_label_P5_context = (gcnew System::Windows::Forms::Label());
			this->label_label_P5 = (gcnew System::Windows::Forms::Label());
			this->panel34 = (gcnew System::Windows::Forms::Panel());
			this->label_label_P13_context = (gcnew System::Windows::Forms::Label());
			this->label_label_P13 = (gcnew System::Windows::Forms::Label());
			this->panel28 = (gcnew System::Windows::Forms::Panel());
			this->label_label_P9_context = (gcnew System::Windows::Forms::Label());
			this->label_label_P9 = (gcnew System::Windows::Forms::Label());
			this->panel35 = (gcnew System::Windows::Forms::Panel());
			this->label_label_P12_context = (gcnew System::Windows::Forms::Label());
			this->label_label_P12 = (gcnew System::Windows::Forms::Label());
			this->panel25 = (gcnew System::Windows::Forms::Panel());
			this->label_label_P4_context = (gcnew System::Windows::Forms::Label());
			this->label_label_P4 = (gcnew System::Windows::Forms::Label());
			this->panel36 = (gcnew System::Windows::Forms::Panel());
			this->label_label_P11_context = (gcnew System::Windows::Forms::Label());
			this->label_label_P11 = (gcnew System::Windows::Forms::Label());
			this->panel29 = (gcnew System::Windows::Forms::Panel());
			this->label_label_P8_context = (gcnew System::Windows::Forms::Label());
			this->label_label_P8 = (gcnew System::Windows::Forms::Label());
			this->panel24 = (gcnew System::Windows::Forms::Panel());
			this->label_label_P3_context = (gcnew System::Windows::Forms::Label());
			this->label_label_P3 = (gcnew System::Windows::Forms::Label());
			this->panel30 = (gcnew System::Windows::Forms::Panel());
			this->label_label_P7_context = (gcnew System::Windows::Forms::Label());
			this->label_label_P7 = (gcnew System::Windows::Forms::Label());
			this->panel23 = (gcnew System::Windows::Forms::Panel());
			this->label_label_P2_context = (gcnew System::Windows::Forms::Label());
			this->label_label_P2 = (gcnew System::Windows::Forms::Label());
			this->panel31 = (gcnew System::Windows::Forms::Panel());
			this->label_label_P6_context = (gcnew System::Windows::Forms::Label());
			this->label_label_P6 = (gcnew System::Windows::Forms::Label());
			this->panel22 = (gcnew System::Windows::Forms::Panel());
			this->label_label_P1_context = (gcnew System::Windows::Forms::Label());
			this->label_label_P1 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label_picBox1_H = (gcnew System::Windows::Forms::Label());
			this->label_picBox1_H_context = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label_picBox2_W = (gcnew System::Windows::Forms::Label());
			this->label_picBox2_W_context = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label_picBox2_H = (gcnew System::Windows::Forms::Label());
			this->label_picBox2_H_context = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->panel43 = (gcnew System::Windows::Forms::Panel());
			this->label_result_log2 = (gcnew System::Windows::Forms::Label());
			this->label_result_log2_context = (gcnew System::Windows::Forms::Label());
			this->panel42 = (gcnew System::Windows::Forms::Panel());
			this->label_selected_folder = (gcnew System::Windows::Forms::Label());
			this->label_selected_folder_context = (gcnew System::Windows::Forms::Label());
			this->panel38 = (gcnew System::Windows::Forms::Panel());
			this->label_Print_Coord_Y = (gcnew System::Windows::Forms::Label());
			this->label_Print_Coord_Y_context = (gcnew System::Windows::Forms::Label());
			this->panel39 = (gcnew System::Windows::Forms::Panel());
			this->label_Print_Coord_X = (gcnew System::Windows::Forms::Label());
			this->label_Print_Coord_X_context = (gcnew System::Windows::Forms::Label());
			this->panel32 = (gcnew System::Windows::Forms::Panel());
			this->label_Read_Coord_Y = (gcnew System::Windows::Forms::Label());
			this->label_Read_Coord_Y_context = (gcnew System::Windows::Forms::Label());
			this->panel21 = (gcnew System::Windows::Forms::Panel());
			this->label_result_log = (gcnew System::Windows::Forms::Label());
			this->label_result_log_context = (gcnew System::Windows::Forms::Label());
			this->panel37 = (gcnew System::Windows::Forms::Panel());
			this->label_Read_Coord_X = (gcnew System::Windows::Forms::Label());
			this->label_Read_Coord_X_context = (gcnew System::Windows::Forms::Label());
			this->panel20 = (gcnew System::Windows::Forms::Panel());
			this->label_result_label = (gcnew System::Windows::Forms::Label());
			this->label_result_label_context = (gcnew System::Windows::Forms::Label());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->label_picBox2_ImgH = (gcnew System::Windows::Forms::Label());
			this->label_picBox2_ImgH_context = (gcnew System::Windows::Forms::Label());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->label_ListBox_Index = (gcnew System::Windows::Forms::Label());
			this->label_ListBox_Index_context = (gcnew System::Windows::Forms::Label());
			this->panel19 = (gcnew System::Windows::Forms::Panel());
			this->label_picBox2_ImgW = (gcnew System::Windows::Forms::Label());
			this->label_picBox2_ImgW_context = (gcnew System::Windows::Forms::Label());
			this->btn_DEBUG_refresh = (gcnew System::Windows::Forms::Button());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->label_Height_Scale = (gcnew System::Windows::Forms::Label());
			this->label_Height_Scale_context = (gcnew System::Windows::Forms::Label());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->label_Width_Scale = (gcnew System::Windows::Forms::Label());
			this->label_Width_Scale_context = (gcnew System::Windows::Forms::Label());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->label_log_D2 = (gcnew System::Windows::Forms::Label());
			this->label_log_D2_context = (gcnew System::Windows::Forms::Label());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->label_label_D2 = (gcnew System::Windows::Forms::Label());
			this->label_label_D2_context = (gcnew System::Windows::Forms::Label());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->label_log_D1 = (gcnew System::Windows::Forms::Label());
			this->label_log_D1_context = (gcnew System::Windows::Forms::Label());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->label_label_D1 = (gcnew System::Windows::Forms::Label());
			this->label_label_D1_context = (gcnew System::Windows::Forms::Label());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->label_log_D0 = (gcnew System::Windows::Forms::Label());
			this->label_log_D0_context = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->label_label_D0 = (gcnew System::Windows::Forms::Label());
			this->label_label_D0_context = (gcnew System::Windows::Forms::Label());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->panel44 = (gcnew System::Windows::Forms::Panel());
			this->label_match_point = (gcnew System::Windows::Forms::Label());
			this->label_match_point_context = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel_frame_count->SuspendLayout();
			this->panel_frame->SuspendLayout();
			this->panel_path->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->panel41->SuspendLayout();
			this->panel40->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->panel27->SuspendLayout();
			this->panel33->SuspendLayout();
			this->panel26->SuspendLayout();
			this->panel34->SuspendLayout();
			this->panel28->SuspendLayout();
			this->panel35->SuspendLayout();
			this->panel25->SuspendLayout();
			this->panel36->SuspendLayout();
			this->panel29->SuspendLayout();
			this->panel24->SuspendLayout();
			this->panel30->SuspendLayout();
			this->panel23->SuspendLayout();
			this->panel31->SuspendLayout();
			this->panel22->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->panel43->SuspendLayout();
			this->panel42->SuspendLayout();
			this->panel38->SuspendLayout();
			this->panel39->SuspendLayout();
			this->panel32->SuspendLayout();
			this->panel21->SuspendLayout();
			this->panel37->SuspendLayout();
			this->panel20->SuspendLayout();
			this->panel18->SuspendLayout();
			this->panel17->SuspendLayout();
			this->panel19->SuspendLayout();
			this->panel16->SuspendLayout();
			this->panel15->SuspendLayout();
			this->panel12->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel13->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel14->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel44->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(60, 41);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(320, 240);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(12, 300);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(401, 56);
			this->trackBar1->TabIndex = 1;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(291, 18);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(122, 39);
			this->button1->TabIndex = 3;
			this->button1->Text = L"start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Load from existed file", L"Output from a new video" });
			this->comboBox1->Location = System::Drawing::Point(6, 24);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(279, 28);
			this->comboBox1->TabIndex = 4;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// btn_play
			// 
			this->btn_play->Enabled = false;
			this->btn_play->Location = System::Drawing::Point(12, 344);
			this->btn_play->Name = L"btn_play";
			this->btn_play->Size = System::Drawing::Size(89, 29);
			this->btn_play->TabIndex = 5;
			this->btn_play->Text = L"play";
			this->btn_play->UseVisualStyleBackColor = true;
			this->btn_play->Click += gcnew System::EventHandler(this, &MyForm::btn_play_Click);
			// 
			// btn_pause
			// 
			this->btn_pause->Enabled = false;
			this->btn_pause->Location = System::Drawing::Point(12, 379);
			this->btn_pause->Name = L"btn_pause";
			this->btn_pause->Size = System::Drawing::Size(89, 29);
			this->btn_pause->TabIndex = 6;
			this->btn_pause->Text = L"pause";
			this->btn_pause->UseVisualStyleBackColor = true;
			this->btn_pause->Click += gcnew System::EventHandler(this, &MyForm::btn_pause_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->panel4);
			this->groupBox1->Controls->Add(this->panel3);
			this->groupBox1->Controls->Add(this->btn_jump_to);
			this->groupBox1->Controls->Add(this->textBox_jump_to);
			this->groupBox1->Controls->Add(this->panel_frame_count);
			this->groupBox1->Controls->Add(this->pictureBox1);
			this->groupBox1->Controls->Add(this->btn_play);
			this->groupBox1->Controls->Add(this->panel_frame);
			this->groupBox1->Controls->Add(this->btn_pause);
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(432, 552);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"VideoView";
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->lab_frame_height);
			this->panel4->Controls->Add(this->lab_frame_height_context);
			this->panel4->Location = System::Drawing::Point(111, 449);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(302, 29);
			this->panel4->TabIndex = 14;
			// 
			// lab_frame_height
			// 
			this->lab_frame_height->AutoSize = true;
			this->lab_frame_height->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_frame_height->Location = System::Drawing::Point(3, 2);
			this->lab_frame_height->Name = L"lab_frame_height";
			this->lab_frame_height->Size = System::Drawing::Size(108, 20);
			this->lab_frame_height->TabIndex = 7;
			this->lab_frame_height->Text = L"Frame Height : ";
			// 
			// lab_frame_height_context
			// 
			this->lab_frame_height_context->AutoSize = true;
			this->lab_frame_height_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_frame_height_context->Location = System::Drawing::Point(125, 2);
			this->lab_frame_height_context->Name = L"lab_frame_height_context";
			this->lab_frame_height_context->Size = System::Drawing::Size(36, 20);
			this->lab_frame_height_context->TabIndex = 2;
			this->lab_frame_height_context->Text = L"N/A";
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->lab_frame_width);
			this->panel3->Controls->Add(this->lab_frame_width_context);
			this->panel3->Location = System::Drawing::Point(111, 414);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(302, 29);
			this->panel3->TabIndex = 13;
			// 
			// lab_frame_width
			// 
			this->lab_frame_width->AutoSize = true;
			this->lab_frame_width->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_frame_width->Location = System::Drawing::Point(3, 2);
			this->lab_frame_width->Name = L"lab_frame_width";
			this->lab_frame_width->Size = System::Drawing::Size(104, 20);
			this->lab_frame_width->TabIndex = 7;
			this->lab_frame_width->Text = L"Frame Width : ";
			// 
			// lab_frame_width_context
			// 
			this->lab_frame_width_context->AutoSize = true;
			this->lab_frame_width_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_frame_width_context->Location = System::Drawing::Point(125, 2);
			this->lab_frame_width_context->Name = L"lab_frame_width_context";
			this->lab_frame_width_context->Size = System::Drawing::Size(36, 20);
			this->lab_frame_width_context->TabIndex = 2;
			this->lab_frame_width_context->Text = L"N/A";
			// 
			// btn_jump_to
			// 
			this->btn_jump_to->Enabled = false;
			this->btn_jump_to->Location = System::Drawing::Point(12, 447);
			this->btn_jump_to->Name = L"btn_jump_to";
			this->btn_jump_to->Size = System::Drawing::Size(89, 31);
			this->btn_jump_to->TabIndex = 14;
			this->btn_jump_to->Text = L"Jump to";
			this->btn_jump_to->UseVisualStyleBackColor = true;
			this->btn_jump_to->Click += gcnew System::EventHandler(this, &MyForm::btn_jump_to_Click);
			// 
			// textBox_jump_to
			// 
			this->textBox_jump_to->Location = System::Drawing::Point(12, 414);
			this->textBox_jump_to->Name = L"textBox_jump_to";
			this->textBox_jump_to->Size = System::Drawing::Size(89, 27);
			this->textBox_jump_to->TabIndex = 13;
			// 
			// panel_frame_count
			// 
			this->panel_frame_count->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_frame_count->Controls->Add(this->lab_frame_count);
			this->panel_frame_count->Controls->Add(this->lab_frame_count_context);
			this->panel_frame_count->Location = System::Drawing::Point(111, 379);
			this->panel_frame_count->Name = L"panel_frame_count";
			this->panel_frame_count->Size = System::Drawing::Size(302, 29);
			this->panel_frame_count->TabIndex = 12;
			// 
			// lab_frame_count
			// 
			this->lab_frame_count->AutoSize = true;
			this->lab_frame_count->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_frame_count->Location = System::Drawing::Point(3, 2);
			this->lab_frame_count->Name = L"lab_frame_count";
			this->lab_frame_count->Size = System::Drawing::Size(119, 20);
			this->lab_frame_count->TabIndex = 7;
			this->lab_frame_count->Text = L"Frame Number : ";
			// 
			// lab_frame_count_context
			// 
			this->lab_frame_count_context->AutoSize = true;
			this->lab_frame_count_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_frame_count_context->Location = System::Drawing::Point(125, 2);
			this->lab_frame_count_context->Name = L"lab_frame_count_context";
			this->lab_frame_count_context->Size = System::Drawing::Size(36, 20);
			this->lab_frame_count_context->TabIndex = 2;
			this->lab_frame_count_context->Text = L"N/A";
			// 
			// panel_frame
			// 
			this->panel_frame->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_frame->Controls->Add(this->lab_frame);
			this->panel_frame->Controls->Add(this->lab_frame_context);
			this->panel_frame->Location = System::Drawing::Point(111, 344);
			this->panel_frame->Name = L"panel_frame";
			this->panel_frame->Size = System::Drawing::Size(302, 29);
			this->panel_frame->TabIndex = 11;
			// 
			// lab_frame
			// 
			this->lab_frame->AutoSize = true;
			this->lab_frame->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_frame->Location = System::Drawing::Point(3, 2);
			this->lab_frame->Name = L"lab_frame";
			this->lab_frame->Size = System::Drawing::Size(61, 20);
			this->lab_frame->TabIndex = 7;
			this->lab_frame->Text = L"Frame : ";
			// 
			// lab_frame_context
			// 
			this->lab_frame_context->AutoSize = true;
			this->lab_frame_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_frame_context->Location = System::Drawing::Point(70, 2);
			this->lab_frame_context->Name = L"lab_frame_context";
			this->lab_frame_context->Size = System::Drawing::Size(36, 20);
			this->lab_frame_context->TabIndex = 2;
			this->lab_frame_context->Text = L"N/A";
			// 
			// panel_path
			// 
			this->panel_path->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_path->Controls->Add(this->lab_path_context);
			this->panel_path->Controls->Add(this->lab_path);
			this->panel_path->Location = System::Drawing::Point(6, 63);
			this->panel_path->Name = L"panel_path";
			this->panel_path->Size = System::Drawing::Size(407, 29);
			this->panel_path->TabIndex = 11;
			// 
			// lab_path_context
			// 
			this->lab_path_context->AutoSize = true;
			this->lab_path_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_path_context->Location = System::Drawing::Point(49, 3);
			this->lab_path_context->Name = L"lab_path_context";
			this->lab_path_context->Size = System::Drawing::Size(36, 20);
			this->lab_path_context->TabIndex = 10;
			this->lab_path_context->Text = L"N/A";
			// 
			// lab_path
			// 
			this->lab_path->AutoSize = true;
			this->lab_path->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lab_path->Location = System::Drawing::Point(3, 3);
			this->lab_path->Name = L"lab_path";
			this->lab_path->Size = System::Drawing::Size(49, 20);
			this->lab_path->TabIndex = 9;
			this->lab_path->Text = L"Path : ";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->panel41);
			this->groupBox2->Controls->Add(this->panel40);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Controls->Add(this->panel_path);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(12, 570);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(432, 185);
			this->groupBox2->TabIndex = 8;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Source";
			// 
			// panel41
			// 
			this->panel41->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel41->Controls->Add(this->label_log_matfile_context);
			this->panel41->Controls->Add(this->label_log_matfile);
			this->panel41->Location = System::Drawing::Point(6, 133);
			this->panel41->Name = L"panel41";
			this->panel41->Size = System::Drawing::Size(407, 29);
			this->panel41->TabIndex = 13;
			// 
			// label_log_matfile_context
			// 
			this->label_log_matfile_context->AutoSize = true;
			this->label_log_matfile_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_log_matfile_context->Location = System::Drawing::Point(100, 3);
			this->label_log_matfile_context->Name = L"label_log_matfile_context";
			this->label_log_matfile_context->Size = System::Drawing::Size(36, 20);
			this->label_log_matfile_context->TabIndex = 10;
			this->label_log_matfile_context->Text = L"N/A";
			this->label_log_matfile_context->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label_log_matfile
			// 
			this->label_log_matfile->AutoSize = true;
			this->label_log_matfile->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_log_matfile->Location = System::Drawing::Point(3, 3);
			this->label_log_matfile->Name = L"label_log_matfile";
			this->label_log_matfile->Size = System::Drawing::Size(89, 20);
			this->label_log_matfile->TabIndex = 9;
			this->label_log_matfile->Text = L"LogMatfile : ";
			// 
			// panel40
			// 
			this->panel40->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel40->Controls->Add(this->label_label_matfile_context);
			this->panel40->Controls->Add(this->label_label_matfile);
			this->panel40->Location = System::Drawing::Point(6, 98);
			this->panel40->Name = L"panel40";
			this->panel40->Size = System::Drawing::Size(407, 29);
			this->panel40->TabIndex = 12;
			// 
			// label_label_matfile_context
			// 
			this->label_label_matfile_context->AutoSize = true;
			this->label_label_matfile_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->label_label_matfile_context->Location = System::Drawing::Point(100, 3);
			this->label_label_matfile_context->Name = L"label_label_matfile_context";
			this->label_label_matfile_context->Size = System::Drawing::Size(36, 20);
			this->label_label_matfile_context->TabIndex = 10;
			this->label_label_matfile_context->Text = L"N/A";
			// 
			// label_label_matfile
			// 
			this->label_label_matfile->AutoSize = true;
			this->label_label_matfile->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_label_matfile->Location = System::Drawing::Point(3, 3);
			this->label_label_matfile->Name = L"label_label_matfile";
			this->label_label_matfile->Size = System::Drawing::Size(99, 20);
			this->label_label_matfile->TabIndex = 9;
			this->label_label_matfile->Text = L"LabelMatfile : ";
			// 
			// btn_preview_mode
			// 
			this->btn_preview_mode->Enabled = false;
			this->btn_preview_mode->Location = System::Drawing::Point(19, 24);
			this->btn_preview_mode->Name = L"btn_preview_mode";
			this->btn_preview_mode->Size = System::Drawing::Size(118, 36);
			this->btn_preview_mode->TabIndex = 10;
			this->btn_preview_mode->Text = L"Preview";
			this->btn_preview_mode->UseVisualStyleBackColor = true;
			this->btn_preview_mode->Click += gcnew System::EventHandler(this, &MyForm::btn_preview_mode_Click);
			// 
			// btn_edit_mode
			// 
			this->btn_edit_mode->Enabled = false;
			this->btn_edit_mode->Location = System::Drawing::Point(19, 66);
			this->btn_edit_mode->Name = L"btn_edit_mode";
			this->btn_edit_mode->Size = System::Drawing::Size(49, 82);
			this->btn_edit_mode->TabIndex = 11;
			this->btn_edit_mode->Text = L"Edit";
			this->btn_edit_mode->UseVisualStyleBackColor = true;
			this->btn_edit_mode->Click += gcnew System::EventHandler(this, &MyForm::btn_edit_mode_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->chkBox_skeletonize_state);
			this->groupBox4->Controls->Add(this->btn_clean_mat);
			this->groupBox4->Controls->Add(this->btn_load_mat);
			this->groupBox4->Controls->Add(this->panel2);
			this->groupBox4->Controls->Add(this->panel1);
			this->groupBox4->Controls->Add(this->listBox1);
			this->groupBox4->Controls->Add(this->btn_edit_modify);
			this->groupBox4->Controls->Add(this->btn_edit_label);
			this->groupBox4->Controls->Add(this->btn_preview_mode);
			this->groupBox4->Controls->Add(this->btn_edit_mode);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->groupBox4->Location = System::Drawing::Point(450, 570);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(843, 185);
			this->groupBox4->TabIndex = 12;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Label Control";
			// 
			// chkBox_skeletonize_state
			// 
			this->chkBox_skeletonize_state->AutoSize = true;
			this->chkBox_skeletonize_state->Location = System::Drawing::Point(25, 152);
			this->chkBox_skeletonize_state->Name = L"chkBox_skeletonize_state";
			this->chkBox_skeletonize_state->Size = System::Drawing::Size(105, 24);
			this->chkBox_skeletonize_state->TabIndex = 20;
			this->chkBox_skeletonize_state->Text = L"Skeletonize";
			this->chkBox_skeletonize_state->UseVisualStyleBackColor = true;
			this->chkBox_skeletonize_state->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// btn_clean_mat
			// 
			this->btn_clean_mat->Enabled = false;
			this->btn_clean_mat->Location = System::Drawing::Point(692, 129);
			this->btn_clean_mat->Name = L"btn_clean_mat";
			this->btn_clean_mat->Size = System::Drawing::Size(145, 39);
			this->btn_clean_mat->TabIndex = 19;
			this->btn_clean_mat->Text = L"Clean";
			this->btn_clean_mat->UseVisualStyleBackColor = true;
			this->btn_clean_mat->Click += gcnew System::EventHandler(this, &MyForm::btn_clean_mat_Click);
			// 
			// btn_load_mat
			// 
			this->btn_load_mat->Enabled = false;
			this->btn_load_mat->Location = System::Drawing::Point(692, 92);
			this->btn_load_mat->Name = L"btn_load_mat";
			this->btn_load_mat->Size = System::Drawing::Size(145, 37);
			this->btn_load_mat->TabIndex = 5;
			this->btn_load_mat->Text = L"Load";
			this->btn_load_mat->UseVisualStyleBackColor = true;
			this->btn_load_mat->Click += gcnew System::EventHandler(this, &MyForm::btn_load_mat_Click);
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->lab_label_x_context);
			this->panel2->Controls->Add(this->lab_label_x);
			this->panel2->Location = System::Drawing::Point(692, 24);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(145, 29);
			this->panel2->TabIndex = 18;
			// 
			// lab_label_x_context
			// 
			this->lab_label_x_context->AutoSize = true;
			this->lab_label_x_context->Location = System::Drawing::Point(38, 4);
			this->lab_label_x_context->Name = L"lab_label_x_context";
			this->lab_label_x_context->Size = System::Drawing::Size(36, 20);
			this->lab_label_x_context->TabIndex = 16;
			this->lab_label_x_context->Text = L"N/A";
			// 
			// lab_label_x
			// 
			this->lab_label_x->AutoSize = true;
			this->lab_label_x->Location = System::Drawing::Point(3, 4);
			this->lab_label_x->Name = L"lab_label_x";
			this->lab_label_x->Size = System::Drawing::Size(29, 20);
			this->lab_label_x->TabIndex = 15;
			this->lab_label_x->Text = L"X : ";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->lab_label_y_context);
			this->panel1->Controls->Add(this->lab_label_y);
			this->panel1->Location = System::Drawing::Point(692, 60);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(145, 29);
			this->panel1->TabIndex = 17;
			// 
			// lab_label_y_context
			// 
			this->lab_label_y_context->AutoSize = true;
			this->lab_label_y_context->Location = System::Drawing::Point(38, 3);
			this->lab_label_y_context->Name = L"lab_label_y_context";
			this->lab_label_y_context->Size = System::Drawing::Size(36, 20);
			this->lab_label_y_context->TabIndex = 17;
			this->lab_label_y_context->Text = L"N/A";
			// 
			// lab_label_y
			// 
			this->lab_label_y->AutoSize = true;
			this->lab_label_y->Location = System::Drawing::Point(3, 3);
			this->lab_label_y->Name = L"lab_label_y";
			this->lab_label_y->Size = System::Drawing::Size(28, 20);
			this->lab_label_y->TabIndex = 16;
			this->lab_label_y->Text = L"Y : ";
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->HorizontalScrollbar = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Location = System::Drawing::Point(143, 24);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(543, 144);
			this->listBox1->TabIndex = 14;
			this->listBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::listBox1_MouseDoubleClick);
			// 
			// btn_edit_modify
			// 
			this->btn_edit_modify->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_edit_modify->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->btn_edit_modify->Location = System::Drawing::Point(74, 112);
			this->btn_edit_modify->Name = L"btn_edit_modify";
			this->btn_edit_modify->Size = System::Drawing::Size(63, 36);
			this->btn_edit_modify->TabIndex = 13;
			this->btn_edit_modify->Text = L"Modify";
			this->btn_edit_modify->UseVisualStyleBackColor = true;
			this->btn_edit_modify->Visible = false;
			this->btn_edit_modify->Click += gcnew System::EventHandler(this, &MyForm::btn_edit_modify_Click);
			// 
			// btn_edit_label
			// 
			this->btn_edit_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_edit_label->Location = System::Drawing::Point(74, 66);
			this->btn_edit_label->Name = L"btn_edit_label";
			this->btn_edit_label->Size = System::Drawing::Size(63, 37);
			this->btn_edit_label->TabIndex = 12;
			this->btn_edit_label->Text = L"Label";
			this->btn_edit_label->UseVisualStyleBackColor = true;
			this->btn_edit_label->Visible = false;
			this->btn_edit_label->Click += gcnew System::EventHandler(this, &MyForm::btn_edit_label_Click);
			// 
			// panel5
			// 
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel5->Controls->Add(this->label_picBox1_W);
			this->panel5->Controls->Add(this->label_picBox1_W_context);
			this->panel5->Location = System::Drawing::Point(22, 41);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(302, 29);
			this->panel5->TabIndex = 15;
			// 
			// label_picBox1_W
			// 
			this->label_picBox1_W->AutoSize = true;
			this->label_picBox1_W->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_picBox1_W->Location = System::Drawing::Point(3, 2);
			this->label_picBox1_W->Name = L"label_picBox1_W";
			this->label_picBox1_W->Size = System::Drawing::Size(105, 20);
			this->label_picBox1_W->TabIndex = 7;
			this->label_picBox1_W->Text = L"PictureBox 1 W";
			// 
			// label_picBox1_W_context
			// 
			this->label_picBox1_W_context->AutoSize = true;
			this->label_picBox1_W_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_picBox1_W_context->Location = System::Drawing::Point(125, 2);
			this->label_picBox1_W_context->Name = L"label_picBox1_W_context";
			this->label_picBox1_W_context->Size = System::Drawing::Size(36, 20);
			this->label_picBox1_W_context->TabIndex = 2;
			this->label_picBox1_W_context->Text = L"N/A";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox2->Location = System::Drawing::Point(14, 41);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(640, 480);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 16;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox2_MouseDown);
			this->pictureBox2->MouseHover += gcnew System::EventHandler(this, &MyForm::pictureBox2_MouseHover);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->panel27);
			this->groupBox3->Controls->Add(this->panel33);
			this->groupBox3->Controls->Add(this->panel26);
			this->groupBox3->Controls->Add(this->panel34);
			this->groupBox3->Controls->Add(this->panel28);
			this->groupBox3->Controls->Add(this->panel35);
			this->groupBox3->Controls->Add(this->panel25);
			this->groupBox3->Controls->Add(this->panel36);
			this->groupBox3->Controls->Add(this->panel29);
			this->groupBox3->Controls->Add(this->panel24);
			this->groupBox3->Controls->Add(this->panel30);
			this->groupBox3->Controls->Add(this->panel23);
			this->groupBox3->Controls->Add(this->panel31);
			this->groupBox3->Controls->Add(this->panel22);
			this->groupBox3->Controls->Add(this->pictureBox2);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->groupBox3->Location = System::Drawing::Point(450, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(843, 552);
			this->groupBox3->TabIndex = 17;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"VideoLabel";
			// 
			// panel27
			// 
			this->panel27->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel27->Controls->Add(this->label_label_P10_context);
			this->panel27->Controls->Add(this->label_label_P10);
			this->panel27->Location = System::Drawing::Point(660, 356);
			this->panel27->Name = L"panel27";
			this->panel27->Size = System::Drawing::Size(177, 29);
			this->panel27->TabIndex = 26;
			// 
			// label_label_P10_context
			// 
			this->label_label_P10_context->AutoSize = true;
			this->label_label_P10_context->Location = System::Drawing::Point(38, 4);
			this->label_label_P10_context->Name = L"label_label_P10_context";
			this->label_label_P10_context->Size = System::Drawing::Size(36, 20);
			this->label_label_P10_context->TabIndex = 16;
			this->label_label_P10_context->Text = L"N/A";
			// 
			// label_label_P10
			// 
			this->label_label_P10->AutoSize = true;
			this->label_label_P10->Location = System::Drawing::Point(3, 4);
			this->label_label_P10->Name = L"label_label_P10";
			this->label_label_P10->Size = System::Drawing::Size(42, 20);
			this->label_label_P10->TabIndex = 15;
			this->label_label_P10->Text = L"P10 : ";
			// 
			// panel33
			// 
			this->panel33->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel33->Controls->Add(this->label_label_P14_context);
			this->panel33->Controls->Add(this->label_label_P14);
			this->panel33->Location = System::Drawing::Point(660, 496);
			this->panel33->Name = L"panel33";
			this->panel33->Size = System::Drawing::Size(177, 29);
			this->panel33->TabIndex = 27;
			// 
			// label_label_P14_context
			// 
			this->label_label_P14_context->AutoSize = true;
			this->label_label_P14_context->Location = System::Drawing::Point(38, 4);
			this->label_label_P14_context->Name = L"label_label_P14_context";
			this->label_label_P14_context->Size = System::Drawing::Size(36, 20);
			this->label_label_P14_context->TabIndex = 16;
			this->label_label_P14_context->Text = L"N/A";
			// 
			// label_label_P14
			// 
			this->label_label_P14->AutoSize = true;
			this->label_label_P14->Location = System::Drawing::Point(3, 4);
			this->label_label_P14->Name = L"label_label_P14";
			this->label_label_P14->Size = System::Drawing::Size(42, 20);
			this->label_label_P14->TabIndex = 15;
			this->label_label_P14->Text = L"P14 : ";
			// 
			// panel26
			// 
			this->panel26->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel26->Controls->Add(this->label_label_P5_context);
			this->panel26->Controls->Add(this->label_label_P5);
			this->panel26->Location = System::Drawing::Point(660, 181);
			this->panel26->Name = L"panel26";
			this->panel26->Size = System::Drawing::Size(177, 29);
			this->panel26->TabIndex = 22;
			// 
			// label_label_P5_context
			// 
			this->label_label_P5_context->AutoSize = true;
			this->label_label_P5_context->Location = System::Drawing::Point(38, 4);
			this->label_label_P5_context->Name = L"label_label_P5_context";
			this->label_label_P5_context->Size = System::Drawing::Size(36, 20);
			this->label_label_P5_context->TabIndex = 16;
			this->label_label_P5_context->Text = L"N/A";
			// 
			// label_label_P5
			// 
			this->label_label_P5->AutoSize = true;
			this->label_label_P5->Location = System::Drawing::Point(3, 4);
			this->label_label_P5->Name = L"label_label_P5";
			this->label_label_P5->Size = System::Drawing::Size(36, 20);
			this->label_label_P5->TabIndex = 15;
			this->label_label_P5->Text = L"P5 : ";
			// 
			// panel34
			// 
			this->panel34->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel34->Controls->Add(this->label_label_P13_context);
			this->panel34->Controls->Add(this->label_label_P13);
			this->panel34->Location = System::Drawing::Point(660, 461);
			this->panel34->Name = L"panel34";
			this->panel34->Size = System::Drawing::Size(177, 29);
			this->panel34->TabIndex = 24;
			// 
			// label_label_P13_context
			// 
			this->label_label_P13_context->AutoSize = true;
			this->label_label_P13_context->Location = System::Drawing::Point(38, 4);
			this->label_label_P13_context->Name = L"label_label_P13_context";
			this->label_label_P13_context->Size = System::Drawing::Size(36, 20);
			this->label_label_P13_context->TabIndex = 16;
			this->label_label_P13_context->Text = L"N/A";
			// 
			// label_label_P13
			// 
			this->label_label_P13->AutoSize = true;
			this->label_label_P13->Location = System::Drawing::Point(3, 4);
			this->label_label_P13->Name = L"label_label_P13";
			this->label_label_P13->Size = System::Drawing::Size(42, 20);
			this->label_label_P13->TabIndex = 15;
			this->label_label_P13->Text = L"P13 : ";
			// 
			// panel28
			// 
			this->panel28->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel28->Controls->Add(this->label_label_P9_context);
			this->panel28->Controls->Add(this->label_label_P9);
			this->panel28->Location = System::Drawing::Point(660, 321);
			this->panel28->Name = L"panel28";
			this->panel28->Size = System::Drawing::Size(177, 29);
			this->panel28->TabIndex = 27;
			// 
			// label_label_P9_context
			// 
			this->label_label_P9_context->AutoSize = true;
			this->label_label_P9_context->Location = System::Drawing::Point(38, 4);
			this->label_label_P9_context->Name = L"label_label_P9_context";
			this->label_label_P9_context->Size = System::Drawing::Size(36, 20);
			this->label_label_P9_context->TabIndex = 16;
			this->label_label_P9_context->Text = L"N/A";
			// 
			// label_label_P9
			// 
			this->label_label_P9->AutoSize = true;
			this->label_label_P9->Location = System::Drawing::Point(3, 4);
			this->label_label_P9->Name = L"label_label_P9";
			this->label_label_P9->Size = System::Drawing::Size(36, 20);
			this->label_label_P9->TabIndex = 15;
			this->label_label_P9->Text = L"P9 : ";
			// 
			// panel35
			// 
			this->panel35->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel35->Controls->Add(this->label_label_P12_context);
			this->panel35->Controls->Add(this->label_label_P12);
			this->panel35->Location = System::Drawing::Point(660, 426);
			this->panel35->Name = L"panel35";
			this->panel35->Size = System::Drawing::Size(177, 29);
			this->panel35->TabIndex = 25;
			// 
			// label_label_P12_context
			// 
			this->label_label_P12_context->AutoSize = true;
			this->label_label_P12_context->Location = System::Drawing::Point(38, 4);
			this->label_label_P12_context->Name = L"label_label_P12_context";
			this->label_label_P12_context->Size = System::Drawing::Size(36, 20);
			this->label_label_P12_context->TabIndex = 16;
			this->label_label_P12_context->Text = L"N/A";
			// 
			// label_label_P12
			// 
			this->label_label_P12->AutoSize = true;
			this->label_label_P12->Location = System::Drawing::Point(3, 4);
			this->label_label_P12->Name = L"label_label_P12";
			this->label_label_P12->Size = System::Drawing::Size(42, 20);
			this->label_label_P12->TabIndex = 15;
			this->label_label_P12->Text = L"P12 : ";
			// 
			// panel25
			// 
			this->panel25->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel25->Controls->Add(this->label_label_P4_context);
			this->panel25->Controls->Add(this->label_label_P4);
			this->panel25->Location = System::Drawing::Point(660, 146);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(177, 29);
			this->panel25->TabIndex = 22;
			// 
			// label_label_P4_context
			// 
			this->label_label_P4_context->AutoSize = true;
			this->label_label_P4_context->Location = System::Drawing::Point(38, 4);
			this->label_label_P4_context->Name = L"label_label_P4_context";
			this->label_label_P4_context->Size = System::Drawing::Size(36, 20);
			this->label_label_P4_context->TabIndex = 16;
			this->label_label_P4_context->Text = L"N/A";
			// 
			// label_label_P4
			// 
			this->label_label_P4->AutoSize = true;
			this->label_label_P4->Location = System::Drawing::Point(3, 4);
			this->label_label_P4->Name = L"label_label_P4";
			this->label_label_P4->Size = System::Drawing::Size(36, 20);
			this->label_label_P4->TabIndex = 15;
			this->label_label_P4->Text = L"P4 : ";
			// 
			// panel36
			// 
			this->panel36->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel36->Controls->Add(this->label_label_P11_context);
			this->panel36->Controls->Add(this->label_label_P11);
			this->panel36->Location = System::Drawing::Point(660, 391);
			this->panel36->Name = L"panel36";
			this->panel36->Size = System::Drawing::Size(177, 29);
			this->panel36->TabIndex = 23;
			// 
			// label_label_P11_context
			// 
			this->label_label_P11_context->AutoSize = true;
			this->label_label_P11_context->Location = System::Drawing::Point(38, 4);
			this->label_label_P11_context->Name = L"label_label_P11_context";
			this->label_label_P11_context->Size = System::Drawing::Size(36, 20);
			this->label_label_P11_context->TabIndex = 16;
			this->label_label_P11_context->Text = L"N/A";
			// 
			// label_label_P11
			// 
			this->label_label_P11->AutoSize = true;
			this->label_label_P11->Location = System::Drawing::Point(3, 4);
			this->label_label_P11->Name = L"label_label_P11";
			this->label_label_P11->Size = System::Drawing::Size(40, 20);
			this->label_label_P11->TabIndex = 15;
			this->label_label_P11->Text = L"P11 : ";
			// 
			// panel29
			// 
			this->panel29->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel29->Controls->Add(this->label_label_P8_context);
			this->panel29->Controls->Add(this->label_label_P8);
			this->panel29->Location = System::Drawing::Point(660, 286);
			this->panel29->Name = L"panel29";
			this->panel29->Size = System::Drawing::Size(177, 29);
			this->panel29->TabIndex = 24;
			// 
			// label_label_P8_context
			// 
			this->label_label_P8_context->AutoSize = true;
			this->label_label_P8_context->Location = System::Drawing::Point(38, 4);
			this->label_label_P8_context->Name = L"label_label_P8_context";
			this->label_label_P8_context->Size = System::Drawing::Size(36, 20);
			this->label_label_P8_context->TabIndex = 16;
			this->label_label_P8_context->Text = L"N/A";
			// 
			// label_label_P8
			// 
			this->label_label_P8->AutoSize = true;
			this->label_label_P8->Location = System::Drawing::Point(3, 4);
			this->label_label_P8->Name = L"label_label_P8";
			this->label_label_P8->Size = System::Drawing::Size(36, 20);
			this->label_label_P8->TabIndex = 15;
			this->label_label_P8->Text = L"P8 : ";
			// 
			// panel24
			// 
			this->panel24->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel24->Controls->Add(this->label_label_P3_context);
			this->panel24->Controls->Add(this->label_label_P3);
			this->panel24->Location = System::Drawing::Point(660, 111);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(177, 29);
			this->panel24->TabIndex = 21;
			// 
			// label_label_P3_context
			// 
			this->label_label_P3_context->AutoSize = true;
			this->label_label_P3_context->Location = System::Drawing::Point(38, 4);
			this->label_label_P3_context->Name = L"label_label_P3_context";
			this->label_label_P3_context->Size = System::Drawing::Size(36, 20);
			this->label_label_P3_context->TabIndex = 16;
			this->label_label_P3_context->Text = L"N/A";
			// 
			// label_label_P3
			// 
			this->label_label_P3->AutoSize = true;
			this->label_label_P3->Location = System::Drawing::Point(3, 4);
			this->label_label_P3->Name = L"label_label_P3";
			this->label_label_P3->Size = System::Drawing::Size(36, 20);
			this->label_label_P3->TabIndex = 15;
			this->label_label_P3->Text = L"P3 : ";
			// 
			// panel30
			// 
			this->panel30->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel30->Controls->Add(this->label_label_P7_context);
			this->panel30->Controls->Add(this->label_label_P7);
			this->panel30->Location = System::Drawing::Point(660, 251);
			this->panel30->Name = L"panel30";
			this->panel30->Size = System::Drawing::Size(177, 29);
			this->panel30->TabIndex = 25;
			// 
			// label_label_P7_context
			// 
			this->label_label_P7_context->AutoSize = true;
			this->label_label_P7_context->Location = System::Drawing::Point(38, 4);
			this->label_label_P7_context->Name = L"label_label_P7_context";
			this->label_label_P7_context->Size = System::Drawing::Size(36, 20);
			this->label_label_P7_context->TabIndex = 16;
			this->label_label_P7_context->Text = L"N/A";
			// 
			// label_label_P7
			// 
			this->label_label_P7->AutoSize = true;
			this->label_label_P7->Location = System::Drawing::Point(3, 4);
			this->label_label_P7->Name = L"label_label_P7";
			this->label_label_P7->Size = System::Drawing::Size(36, 20);
			this->label_label_P7->TabIndex = 15;
			this->label_label_P7->Text = L"P7 : ";
			// 
			// panel23
			// 
			this->panel23->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel23->Controls->Add(this->label_label_P2_context);
			this->panel23->Controls->Add(this->label_label_P2);
			this->panel23->Location = System::Drawing::Point(660, 76);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(177, 29);
			this->panel23->TabIndex = 21;
			// 
			// label_label_P2_context
			// 
			this->label_label_P2_context->AutoSize = true;
			this->label_label_P2_context->Location = System::Drawing::Point(38, 4);
			this->label_label_P2_context->Name = L"label_label_P2_context";
			this->label_label_P2_context->Size = System::Drawing::Size(36, 20);
			this->label_label_P2_context->TabIndex = 16;
			this->label_label_P2_context->Text = L"N/A";
			// 
			// label_label_P2
			// 
			this->label_label_P2->AutoSize = true;
			this->label_label_P2->Location = System::Drawing::Point(3, 4);
			this->label_label_P2->Name = L"label_label_P2";
			this->label_label_P2->Size = System::Drawing::Size(36, 20);
			this->label_label_P2->TabIndex = 15;
			this->label_label_P2->Text = L"P2 : ";
			// 
			// panel31
			// 
			this->panel31->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel31->Controls->Add(this->label_label_P6_context);
			this->panel31->Controls->Add(this->label_label_P6);
			this->panel31->Location = System::Drawing::Point(660, 216);
			this->panel31->Name = L"panel31";
			this->panel31->Size = System::Drawing::Size(177, 29);
			this->panel31->TabIndex = 23;
			// 
			// label_label_P6_context
			// 
			this->label_label_P6_context->AutoSize = true;
			this->label_label_P6_context->Location = System::Drawing::Point(38, 4);
			this->label_label_P6_context->Name = L"label_label_P6_context";
			this->label_label_P6_context->Size = System::Drawing::Size(36, 20);
			this->label_label_P6_context->TabIndex = 16;
			this->label_label_P6_context->Text = L"N/A";
			// 
			// label_label_P6
			// 
			this->label_label_P6->AutoSize = true;
			this->label_label_P6->Location = System::Drawing::Point(3, 4);
			this->label_label_P6->Name = L"label_label_P6";
			this->label_label_P6->Size = System::Drawing::Size(36, 20);
			this->label_label_P6->TabIndex = 15;
			this->label_label_P6->Text = L"P6 : ";
			// 
			// panel22
			// 
			this->panel22->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel22->Controls->Add(this->label_label_P1_context);
			this->panel22->Controls->Add(this->label_label_P1);
			this->panel22->Location = System::Drawing::Point(660, 41);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(177, 29);
			this->panel22->TabIndex = 20;
			// 
			// label_label_P1_context
			// 
			this->label_label_P1_context->AutoSize = true;
			this->label_label_P1_context->Location = System::Drawing::Point(38, 4);
			this->label_label_P1_context->Name = L"label_label_P1_context";
			this->label_label_P1_context->Size = System::Drawing::Size(36, 20);
			this->label_label_P1_context->TabIndex = 16;
			this->label_label_P1_context->Text = L"N/A";
			// 
			// label_label_P1
			// 
			this->label_label_P1->AutoSize = true;
			this->label_label_P1->Location = System::Drawing::Point(3, 4);
			this->label_label_P1->Name = L"label_label_P1";
			this->label_label_P1->Size = System::Drawing::Size(34, 20);
			this->label_label_P1->TabIndex = 15;
			this->label_label_P1->Text = L"P1 : ";
			// 
			// panel6
			// 
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->Controls->Add(this->label_picBox1_H);
			this->panel6->Controls->Add(this->label_picBox1_H_context);
			this->panel6->Location = System::Drawing::Point(22, 76);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(302, 29);
			this->panel6->TabIndex = 16;
			// 
			// label_picBox1_H
			// 
			this->label_picBox1_H->AutoSize = true;
			this->label_picBox1_H->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_picBox1_H->Location = System::Drawing::Point(3, 2);
			this->label_picBox1_H->Name = L"label_picBox1_H";
			this->label_picBox1_H->Size = System::Drawing::Size(101, 20);
			this->label_picBox1_H->TabIndex = 7;
			this->label_picBox1_H->Text = L"PictureBox 1 H";
			// 
			// label_picBox1_H_context
			// 
			this->label_picBox1_H_context->AutoSize = true;
			this->label_picBox1_H_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_picBox1_H_context->Location = System::Drawing::Point(125, 2);
			this->label_picBox1_H_context->Name = L"label_picBox1_H_context";
			this->label_picBox1_H_context->Size = System::Drawing::Size(36, 20);
			this->label_picBox1_H_context->TabIndex = 2;
			this->label_picBox1_H_context->Text = L"N/A";
			// 
			// panel7
			// 
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel7->Controls->Add(this->label_picBox2_W);
			this->panel7->Controls->Add(this->label_picBox2_W_context);
			this->panel7->Location = System::Drawing::Point(22, 111);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(302, 29);
			this->panel7->TabIndex = 16;
			// 
			// label_picBox2_W
			// 
			this->label_picBox2_W->AutoSize = true;
			this->label_picBox2_W->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_picBox2_W->Location = System::Drawing::Point(3, 2);
			this->label_picBox2_W->Name = L"label_picBox2_W";
			this->label_picBox2_W->Size = System::Drawing::Size(107, 20);
			this->label_picBox2_W->TabIndex = 7;
			this->label_picBox2_W->Text = L"PictureBox 2 W";
			// 
			// label_picBox2_W_context
			// 
			this->label_picBox2_W_context->AutoSize = true;
			this->label_picBox2_W_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_picBox2_W_context->Location = System::Drawing::Point(125, 2);
			this->label_picBox2_W_context->Name = L"label_picBox2_W_context";
			this->label_picBox2_W_context->Size = System::Drawing::Size(36, 20);
			this->label_picBox2_W_context->TabIndex = 2;
			this->label_picBox2_W_context->Text = L"N/A";
			// 
			// panel8
			// 
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel8->Controls->Add(this->label_picBox2_H);
			this->panel8->Controls->Add(this->label_picBox2_H_context);
			this->panel8->Location = System::Drawing::Point(22, 144);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(302, 29);
			this->panel8->TabIndex = 17;
			// 
			// label_picBox2_H
			// 
			this->label_picBox2_H->AutoSize = true;
			this->label_picBox2_H->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_picBox2_H->Location = System::Drawing::Point(3, 2);
			this->label_picBox2_H->Name = L"label_picBox2_H";
			this->label_picBox2_H->Size = System::Drawing::Size(103, 20);
			this->label_picBox2_H->TabIndex = 7;
			this->label_picBox2_H->Text = L"PictureBox 2 H";
			// 
			// label_picBox2_H_context
			// 
			this->label_picBox2_H_context->AutoSize = true;
			this->label_picBox2_H_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_picBox2_H_context->Location = System::Drawing::Point(125, 2);
			this->label_picBox2_H_context->Name = L"label_picBox2_H_context";
			this->label_picBox2_H_context->Size = System::Drawing::Size(36, 20);
			this->label_picBox2_H_context->TabIndex = 2;
			this->label_picBox2_H_context->Text = L"N/A";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->panel44);
			this->groupBox5->Controls->Add(this->panel43);
			this->groupBox5->Controls->Add(this->panel42);
			this->groupBox5->Controls->Add(this->panel38);
			this->groupBox5->Controls->Add(this->panel39);
			this->groupBox5->Controls->Add(this->panel32);
			this->groupBox5->Controls->Add(this->panel21);
			this->groupBox5->Controls->Add(this->panel37);
			this->groupBox5->Controls->Add(this->panel20);
			this->groupBox5->Controls->Add(this->panel18);
			this->groupBox5->Controls->Add(this->panel17);
			this->groupBox5->Controls->Add(this->panel19);
			this->groupBox5->Controls->Add(this->btn_DEBUG_refresh);
			this->groupBox5->Controls->Add(this->panel16);
			this->groupBox5->Controls->Add(this->panel15);
			this->groupBox5->Controls->Add(this->panel12);
			this->groupBox5->Controls->Add(this->panel11);
			this->groupBox5->Controls->Add(this->panel13);
			this->groupBox5->Controls->Add(this->panel10);
			this->groupBox5->Controls->Add(this->panel14);
			this->groupBox5->Controls->Add(this->panel9);
			this->groupBox5->Controls->Add(this->panel5);
			this->groupBox5->Controls->Add(this->panel8);
			this->groupBox5->Controls->Add(this->panel7);
			this->groupBox5->Controls->Add(this->panel6);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->groupBox5->Location = System::Drawing::Point(1299, 12);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(339, 1284);
			this->groupBox5->TabIndex = 18;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"DebugConfiguration";
			// 
			// panel43
			// 
			this->panel43->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel43->Controls->Add(this->label_result_log2);
			this->panel43->Controls->Add(this->label_result_log2_context);
			this->panel43->Location = System::Drawing::Point(22, 816);
			this->panel43->Name = L"panel43";
			this->panel43->Size = System::Drawing::Size(302, 29);
			this->panel43->TabIndex = 25;
			// 
			// label_result_log2
			// 
			this->label_result_log2->AutoSize = true;
			this->label_result_log2->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_result_log2->Location = System::Drawing::Point(3, 2);
			this->label_result_log2->Name = L"label_result_log2";
			this->label_result_log2->Size = System::Drawing::Size(86, 20);
			this->label_result_log2->TabIndex = 7;
			this->label_result_log2->Text = L"LogData2 R";
			// 
			// label_result_log2_context
			// 
			this->label_result_log2_context->AutoSize = true;
			this->label_result_log2_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_result_log2_context->Location = System::Drawing::Point(138, 2);
			this->label_result_log2_context->Name = L"label_result_log2_context";
			this->label_result_log2_context->Size = System::Drawing::Size(36, 20);
			this->label_result_log2_context->TabIndex = 2;
			this->label_result_log2_context->Text = L"N/A";
			// 
			// panel42
			// 
			this->panel42->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel42->Controls->Add(this->label_selected_folder);
			this->panel42->Controls->Add(this->label_selected_folder_context);
			this->panel42->Location = System::Drawing::Point(22, 781);
			this->panel42->Name = L"panel42";
			this->panel42->Size = System::Drawing::Size(302, 29);
			this->panel42->TabIndex = 24;
			// 
			// label_selected_folder
			// 
			this->label_selected_folder->AutoSize = true;
			this->label_selected_folder->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_selected_folder->Location = System::Drawing::Point(3, 2);
			this->label_selected_folder->Name = L"label_selected_folder";
			this->label_selected_folder->Size = System::Drawing::Size(106, 20);
			this->label_selected_folder->TabIndex = 7;
			this->label_selected_folder->Text = L"SelectedFolder";
			// 
			// label_selected_folder_context
			// 
			this->label_selected_folder_context->AutoSize = true;
			this->label_selected_folder_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->label_selected_folder_context->Location = System::Drawing::Point(138, 2);
			this->label_selected_folder_context->Name = L"label_selected_folder_context";
			this->label_selected_folder_context->Size = System::Drawing::Size(36, 20);
			this->label_selected_folder_context->TabIndex = 2;
			this->label_selected_folder_context->Text = L"N/A";
			// 
			// panel38
			// 
			this->panel38->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel38->Controls->Add(this->label_Print_Coord_Y);
			this->panel38->Controls->Add(this->label_Print_Coord_Y_context);
			this->panel38->Location = System::Drawing::Point(22, 745);
			this->panel38->Name = L"panel38";
			this->panel38->Size = System::Drawing::Size(302, 29);
			this->panel38->TabIndex = 23;
			// 
			// label_Print_Coord_Y
			// 
			this->label_Print_Coord_Y->AutoSize = true;
			this->label_Print_Coord_Y->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_Print_Coord_Y->Location = System::Drawing::Point(3, 2);
			this->label_Print_Coord_Y->Name = L"label_Print_Coord_Y";
			this->label_Print_Coord_Y->Size = System::Drawing::Size(91, 20);
			this->label_Print_Coord_Y->TabIndex = 7;
			this->label_Print_Coord_Y->Text = L"PrintCoord Y";
			// 
			// label_Print_Coord_Y_context
			// 
			this->label_Print_Coord_Y_context->AutoSize = true;
			this->label_Print_Coord_Y_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->label_Print_Coord_Y_context->Location = System::Drawing::Point(138, 2);
			this->label_Print_Coord_Y_context->Name = L"label_Print_Coord_Y_context";
			this->label_Print_Coord_Y_context->Size = System::Drawing::Size(36, 20);
			this->label_Print_Coord_Y_context->TabIndex = 2;
			this->label_Print_Coord_Y_context->Text = L"N/A";
			// 
			// panel39
			// 
			this->panel39->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel39->Controls->Add(this->label_Print_Coord_X);
			this->panel39->Controls->Add(this->label_Print_Coord_X_context);
			this->panel39->Location = System::Drawing::Point(22, 710);
			this->panel39->Name = L"panel39";
			this->panel39->Size = System::Drawing::Size(302, 29);
			this->panel39->TabIndex = 24;
			// 
			// label_Print_Coord_X
			// 
			this->label_Print_Coord_X->AutoSize = true;
			this->label_Print_Coord_X->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_Print_Coord_X->Location = System::Drawing::Point(3, 2);
			this->label_Print_Coord_X->Name = L"label_Print_Coord_X";
			this->label_Print_Coord_X->Size = System::Drawing::Size(92, 20);
			this->label_Print_Coord_X->TabIndex = 7;
			this->label_Print_Coord_X->Text = L"PrintCoord X";
			// 
			// label_Print_Coord_X_context
			// 
			this->label_Print_Coord_X_context->AutoSize = true;
			this->label_Print_Coord_X_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->label_Print_Coord_X_context->Location = System::Drawing::Point(138, 2);
			this->label_Print_Coord_X_context->Name = L"label_Print_Coord_X_context";
			this->label_Print_Coord_X_context->Size = System::Drawing::Size(36, 20);
			this->label_Print_Coord_X_context->TabIndex = 2;
			this->label_Print_Coord_X_context->Text = L"N/A";
			// 
			// panel32
			// 
			this->panel32->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel32->Controls->Add(this->label_Read_Coord_Y);
			this->panel32->Controls->Add(this->label_Read_Coord_Y_context);
			this->panel32->Location = System::Drawing::Point(22, 675);
			this->panel32->Name = L"panel32";
			this->panel32->Size = System::Drawing::Size(302, 29);
			this->panel32->TabIndex = 21;
			// 
			// label_Read_Coord_Y
			// 
			this->label_Read_Coord_Y->AutoSize = true;
			this->label_Read_Coord_Y->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_Read_Coord_Y->Location = System::Drawing::Point(3, 2);
			this->label_Read_Coord_Y->Name = L"label_Read_Coord_Y";
			this->label_Read_Coord_Y->Size = System::Drawing::Size(96, 20);
			this->label_Read_Coord_Y->TabIndex = 7;
			this->label_Read_Coord_Y->Text = L"ReadCoord Y";
			// 
			// label_Read_Coord_Y_context
			// 
			this->label_Read_Coord_Y_context->AutoSize = true;
			this->label_Read_Coord_Y_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->label_Read_Coord_Y_context->Location = System::Drawing::Point(138, 2);
			this->label_Read_Coord_Y_context->Name = L"label_Read_Coord_Y_context";
			this->label_Read_Coord_Y_context->Size = System::Drawing::Size(36, 20);
			this->label_Read_Coord_Y_context->TabIndex = 2;
			this->label_Read_Coord_Y_context->Text = L"N/A";
			// 
			// panel21
			// 
			this->panel21->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel21->Controls->Add(this->label_result_log);
			this->panel21->Controls->Add(this->label_result_log_context);
			this->panel21->Location = System::Drawing::Point(22, 605);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(302, 29);
			this->panel21->TabIndex = 20;
			// 
			// label_result_log
			// 
			this->label_result_log->AutoSize = true;
			this->label_result_log->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_result_log->Location = System::Drawing::Point(3, 2);
			this->label_result_log->Name = L"label_result_log";
			this->label_result_log->Size = System::Drawing::Size(78, 20);
			this->label_result_log->TabIndex = 7;
			this->label_result_log->Text = L"LogData R";
			// 
			// label_result_log_context
			// 
			this->label_result_log_context->AutoSize = true;
			this->label_result_log_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_result_log_context->Location = System::Drawing::Point(138, 2);
			this->label_result_log_context->Name = L"label_result_log_context";
			this->label_result_log_context->Size = System::Drawing::Size(36, 20);
			this->label_result_log_context->TabIndex = 2;
			this->label_result_log_context->Text = L"N/A";
			// 
			// panel37
			// 
			this->panel37->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel37->Controls->Add(this->label_Read_Coord_X);
			this->panel37->Controls->Add(this->label_Read_Coord_X_context);
			this->panel37->Location = System::Drawing::Point(22, 640);
			this->panel37->Name = L"panel37";
			this->panel37->Size = System::Drawing::Size(302, 29);
			this->panel37->TabIndex = 22;
			// 
			// label_Read_Coord_X
			// 
			this->label_Read_Coord_X->AutoSize = true;
			this->label_Read_Coord_X->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_Read_Coord_X->Location = System::Drawing::Point(3, 2);
			this->label_Read_Coord_X->Name = L"label_Read_Coord_X";
			this->label_Read_Coord_X->Size = System::Drawing::Size(97, 20);
			this->label_Read_Coord_X->TabIndex = 7;
			this->label_Read_Coord_X->Text = L"ReadCoord X";
			// 
			// label_Read_Coord_X_context
			// 
			this->label_Read_Coord_X_context->AutoSize = true;
			this->label_Read_Coord_X_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->label_Read_Coord_X_context->Location = System::Drawing::Point(138, 2);
			this->label_Read_Coord_X_context->Name = L"label_Read_Coord_X_context";
			this->label_Read_Coord_X_context->Size = System::Drawing::Size(36, 20);
			this->label_Read_Coord_X_context->TabIndex = 2;
			this->label_Read_Coord_X_context->Text = L"N/A";
			// 
			// panel20
			// 
			this->panel20->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel20->Controls->Add(this->label_result_label);
			this->panel20->Controls->Add(this->label_result_label_context);
			this->panel20->Location = System::Drawing::Point(22, 570);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(302, 29);
			this->panel20->TabIndex = 20;
			// 
			// label_result_label
			// 
			this->label_result_label->AutoSize = true;
			this->label_result_label->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_result_label->Location = System::Drawing::Point(3, 2);
			this->label_result_label->Name = L"label_result_label";
			this->label_result_label->Size = System::Drawing::Size(88, 20);
			this->label_result_label->TabIndex = 7;
			this->label_result_label->Text = L"LabelData R";
			// 
			// label_result_label_context
			// 
			this->label_result_label_context->AutoSize = true;
			this->label_result_label_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->label_result_label_context->Location = System::Drawing::Point(138, 2);
			this->label_result_label_context->Name = L"label_result_label_context";
			this->label_result_label_context->Size = System::Drawing::Size(36, 20);
			this->label_result_label_context->TabIndex = 2;
			this->label_result_label_context->Text = L"N/A";
			// 
			// panel18
			// 
			this->panel18->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel18->Controls->Add(this->label_picBox2_ImgH);
			this->panel18->Controls->Add(this->label_picBox2_ImgH_context);
			this->panel18->Location = System::Drawing::Point(22, 535);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(302, 29);
			this->panel18->TabIndex = 19;
			// 
			// label_picBox2_ImgH
			// 
			this->label_picBox2_ImgH->AutoSize = true;
			this->label_picBox2_ImgH->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_picBox2_ImgH->Location = System::Drawing::Point(3, 2);
			this->label_picBox2_ImgH->Name = L"label_picBox2_ImgH";
			this->label_picBox2_ImgH->Size = System::Drawing::Size(129, 20);
			this->label_picBox2_ImgH->TabIndex = 7;
			this->label_picBox2_ImgH->Text = L"PictureBox 2 ImgH";
			// 
			// label_picBox2_ImgH_context
			// 
			this->label_picBox2_ImgH_context->AutoSize = true;
			this->label_picBox2_ImgH_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->label_picBox2_ImgH_context->Location = System::Drawing::Point(138, 2);
			this->label_picBox2_ImgH_context->Name = L"label_picBox2_ImgH_context";
			this->label_picBox2_ImgH_context->Size = System::Drawing::Size(36, 20);
			this->label_picBox2_ImgH_context->TabIndex = 2;
			this->label_picBox2_ImgH_context->Text = L"N/A";
			// 
			// panel17
			// 
			this->panel17->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel17->Controls->Add(this->label_ListBox_Index);
			this->panel17->Controls->Add(this->label_ListBox_Index_context);
			this->panel17->Location = System::Drawing::Point(22, 465);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(302, 29);
			this->panel17->TabIndex = 22;
			// 
			// label_ListBox_Index
			// 
			this->label_ListBox_Index->AutoSize = true;
			this->label_ListBox_Index->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_ListBox_Index->Location = System::Drawing::Point(3, 2);
			this->label_ListBox_Index->Name = L"label_ListBox_Index";
			this->label_ListBox_Index->Size = System::Drawing::Size(94, 20);
			this->label_ListBox_Index->TabIndex = 7;
			this->label_ListBox_Index->Text = L"ListBox Index";
			// 
			// label_ListBox_Index_context
			// 
			this->label_ListBox_Index_context->AutoSize = true;
			this->label_ListBox_Index_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->label_ListBox_Index_context->Location = System::Drawing::Point(125, 2);
			this->label_ListBox_Index_context->Name = L"label_ListBox_Index_context";
			this->label_ListBox_Index_context->Size = System::Drawing::Size(36, 20);
			this->label_ListBox_Index_context->TabIndex = 2;
			this->label_ListBox_Index_context->Text = L"N/A";
			// 
			// panel19
			// 
			this->panel19->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel19->Controls->Add(this->label_picBox2_ImgW);
			this->panel19->Controls->Add(this->label_picBox2_ImgW_context);
			this->panel19->Location = System::Drawing::Point(22, 500);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(302, 29);
			this->panel19->TabIndex = 18;
			// 
			// label_picBox2_ImgW
			// 
			this->label_picBox2_ImgW->AutoSize = true;
			this->label_picBox2_ImgW->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_picBox2_ImgW->Location = System::Drawing::Point(3, 2);
			this->label_picBox2_ImgW->Name = L"label_picBox2_ImgW";
			this->label_picBox2_ImgW->Size = System::Drawing::Size(133, 20);
			this->label_picBox2_ImgW->TabIndex = 7;
			this->label_picBox2_ImgW->Text = L"PictureBox 2 ImgW";
			// 
			// label_picBox2_ImgW_context
			// 
			this->label_picBox2_ImgW_context->AutoSize = true;
			this->label_picBox2_ImgW_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->label_picBox2_ImgW_context->Location = System::Drawing::Point(138, 2);
			this->label_picBox2_ImgW_context->Name = L"label_picBox2_ImgW_context";
			this->label_picBox2_ImgW_context->Size = System::Drawing::Size(36, 20);
			this->label_picBox2_ImgW_context->TabIndex = 2;
			this->label_picBox2_ImgW_context->Text = L"N/A";
			// 
			// btn_DEBUG_refresh
			// 
			this->btn_DEBUG_refresh->Location = System::Drawing::Point(226, 1231);
			this->btn_DEBUG_refresh->Name = L"btn_DEBUG_refresh";
			this->btn_DEBUG_refresh->Size = System::Drawing::Size(107, 47);
			this->btn_DEBUG_refresh->TabIndex = 22;
			this->btn_DEBUG_refresh->Text = L"Refresh";
			this->btn_DEBUG_refresh->UseVisualStyleBackColor = true;
			this->btn_DEBUG_refresh->Click += gcnew System::EventHandler(this, &MyForm::btn_DEBUG_refresh_Click);
			// 
			// panel16
			// 
			this->panel16->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel16->Controls->Add(this->label_Height_Scale);
			this->panel16->Controls->Add(this->label_Height_Scale_context);
			this->panel16->Location = System::Drawing::Point(22, 430);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(302, 29);
			this->panel16->TabIndex = 21;
			// 
			// label_Height_Scale
			// 
			this->label_Height_Scale->AutoSize = true;
			this->label_Height_Scale->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_Height_Scale->Location = System::Drawing::Point(3, 2);
			this->label_Height_Scale->Name = L"label_Height_Scale";
			this->label_Height_Scale->Size = System::Drawing::Size(90, 20);
			this->label_Height_Scale->TabIndex = 7;
			this->label_Height_Scale->Text = L"Height Scale";
			// 
			// label_Height_Scale_context
			// 
			this->label_Height_Scale_context->AutoSize = true;
			this->label_Height_Scale_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->label_Height_Scale_context->Location = System::Drawing::Point(125, 2);
			this->label_Height_Scale_context->Name = L"label_Height_Scale_context";
			this->label_Height_Scale_context->Size = System::Drawing::Size(36, 20);
			this->label_Height_Scale_context->TabIndex = 2;
			this->label_Height_Scale_context->Text = L"N/A";
			// 
			// panel15
			// 
			this->panel15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel15->Controls->Add(this->label_Width_Scale);
			this->panel15->Controls->Add(this->label_Width_Scale_context);
			this->panel15->Location = System::Drawing::Point(22, 395);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(302, 29);
			this->panel15->TabIndex = 20;
			// 
			// label_Width_Scale
			// 
			this->label_Width_Scale->AutoSize = true;
			this->label_Width_Scale->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_Width_Scale->Location = System::Drawing::Point(3, 2);
			this->label_Width_Scale->Name = L"label_Width_Scale";
			this->label_Width_Scale->Size = System::Drawing::Size(86, 20);
			this->label_Width_Scale->TabIndex = 7;
			this->label_Width_Scale->Text = L"Width Scale";
			// 
			// label_Width_Scale_context
			// 
			this->label_Width_Scale_context->AutoSize = true;
			this->label_Width_Scale_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_Width_Scale_context->Location = System::Drawing::Point(125, 2);
			this->label_Width_Scale_context->Name = L"label_Width_Scale_context";
			this->label_Width_Scale_context->Size = System::Drawing::Size(36, 20);
			this->label_Width_Scale_context->TabIndex = 2;
			this->label_Width_Scale_context->Text = L"N/A";
			// 
			// panel12
			// 
			this->panel12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel12->Controls->Add(this->label_log_D2);
			this->panel12->Controls->Add(this->label_log_D2_context);
			this->panel12->Location = System::Drawing::Point(22, 360);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(302, 29);
			this->panel12->TabIndex = 19;
			// 
			// label_log_D2
			// 
			this->label_log_D2->AutoSize = true;
			this->label_log_D2->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_log_D2->Location = System::Drawing::Point(3, 2);
			this->label_log_D2->Name = L"label_log_D2";
			this->label_log_D2->Size = System::Drawing::Size(76, 20);
			this->label_log_D2->TabIndex = 7;
			this->label_log_D2->Text = L"Log Dim 2";
			// 
			// label_log_D2_context
			// 
			this->label_log_D2_context->AutoSize = true;
			this->label_log_D2_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_log_D2_context->Location = System::Drawing::Point(125, 2);
			this->label_log_D2_context->Name = L"label_log_D2_context";
			this->label_log_D2_context->Size = System::Drawing::Size(36, 20);
			this->label_log_D2_context->TabIndex = 2;
			this->label_log_D2_context->Text = L"N/A";
			// 
			// panel11
			// 
			this->panel11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel11->Controls->Add(this->label_label_D2);
			this->panel11->Controls->Add(this->label_label_D2_context);
			this->panel11->Location = System::Drawing::Point(22, 249);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(302, 29);
			this->panel11->TabIndex = 18;
			// 
			// label_label_D2
			// 
			this->label_label_D2->AutoSize = true;
			this->label_label_D2->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_label_D2->Location = System::Drawing::Point(3, 2);
			this->label_label_D2->Name = L"label_label_D2";
			this->label_label_D2->Size = System::Drawing::Size(86, 20);
			this->label_label_D2->TabIndex = 7;
			this->label_label_D2->Text = L"Label Dim 2";
			// 
			// label_label_D2_context
			// 
			this->label_label_D2_context->AutoSize = true;
			this->label_label_D2_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_label_D2_context->Location = System::Drawing::Point(125, 2);
			this->label_label_D2_context->Name = L"label_label_D2_context";
			this->label_label_D2_context->Size = System::Drawing::Size(36, 20);
			this->label_label_D2_context->TabIndex = 2;
			this->label_label_D2_context->Text = L"N/A";
			// 
			// panel13
			// 
			this->panel13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel13->Controls->Add(this->label_log_D1);
			this->panel13->Controls->Add(this->label_log_D1_context);
			this->panel13->Location = System::Drawing::Point(22, 322);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(302, 29);
			this->panel13->TabIndex = 20;
			// 
			// label_log_D1
			// 
			this->label_log_D1->AutoSize = true;
			this->label_log_D1->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_log_D1->Location = System::Drawing::Point(3, 2);
			this->label_log_D1->Name = L"label_log_D1";
			this->label_log_D1->Size = System::Drawing::Size(74, 20);
			this->label_log_D1->TabIndex = 7;
			this->label_log_D1->Text = L"Log Dim 1";
			// 
			// label_log_D1_context
			// 
			this->label_log_D1_context->AutoSize = true;
			this->label_log_D1_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_log_D1_context->Location = System::Drawing::Point(125, 2);
			this->label_log_D1_context->Name = L"label_log_D1_context";
			this->label_log_D1_context->Size = System::Drawing::Size(36, 20);
			this->label_log_D1_context->TabIndex = 2;
			this->label_log_D1_context->Text = L"N/A";
			// 
			// panel10
			// 
			this->panel10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel10->Controls->Add(this->label_label_D1);
			this->panel10->Controls->Add(this->label_label_D1_context);
			this->panel10->Location = System::Drawing::Point(22, 214);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(302, 29);
			this->panel10->TabIndex = 18;
			// 
			// label_label_D1
			// 
			this->label_label_D1->AutoSize = true;
			this->label_label_D1->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_label_D1->Location = System::Drawing::Point(3, 2);
			this->label_label_D1->Name = L"label_label_D1";
			this->label_label_D1->Size = System::Drawing::Size(84, 20);
			this->label_label_D1->TabIndex = 7;
			this->label_label_D1->Text = L"Label Dim 1";
			// 
			// label_label_D1_context
			// 
			this->label_label_D1_context->AutoSize = true;
			this->label_label_D1_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_label_D1_context->Location = System::Drawing::Point(125, 2);
			this->label_label_D1_context->Name = L"label_label_D1_context";
			this->label_label_D1_context->Size = System::Drawing::Size(36, 20);
			this->label_label_D1_context->TabIndex = 2;
			this->label_label_D1_context->Text = L"N/A";
			// 
			// panel14
			// 
			this->panel14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel14->Controls->Add(this->label_log_D0);
			this->panel14->Controls->Add(this->label_log_D0_context);
			this->panel14->Location = System::Drawing::Point(22, 284);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(302, 29);
			this->panel14->TabIndex = 21;
			// 
			// label_log_D0
			// 
			this->label_log_D0->AutoSize = true;
			this->label_log_D0->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_log_D0->Location = System::Drawing::Point(3, 2);
			this->label_log_D0->Name = L"label_log_D0";
			this->label_log_D0->Size = System::Drawing::Size(76, 20);
			this->label_log_D0->TabIndex = 7;
			this->label_log_D0->Text = L"Log Dim 0";
			// 
			// label_log_D0_context
			// 
			this->label_log_D0_context->AutoSize = true;
			this->label_log_D0_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_log_D0_context->Location = System::Drawing::Point(125, 2);
			this->label_log_D0_context->Name = L"label_log_D0_context";
			this->label_log_D0_context->Size = System::Drawing::Size(36, 20);
			this->label_log_D0_context->TabIndex = 2;
			this->label_log_D0_context->Text = L"N/A";
			// 
			// panel9
			// 
			this->panel9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel9->Controls->Add(this->label_label_D0);
			this->panel9->Controls->Add(this->label_label_D0_context);
			this->panel9->Location = System::Drawing::Point(22, 179);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(302, 29);
			this->panel9->TabIndex = 18;
			// 
			// label_label_D0
			// 
			this->label_label_D0->AutoSize = true;
			this->label_label_D0->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_label_D0->Location = System::Drawing::Point(3, 2);
			this->label_label_D0->Name = L"label_label_D0";
			this->label_label_D0->Size = System::Drawing::Size(86, 20);
			this->label_label_D0->TabIndex = 7;
			this->label_label_D0->Text = L"Label Dim 0";
			// 
			// label_label_D0_context
			// 
			this->label_label_D0_context->AutoSize = true;
			this->label_label_D0_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_label_D0_context->Location = System::Drawing::Point(125, 2);
			this->label_label_D0_context->Name = L"label_label_D0_context";
			this->label_label_D0_context->Size = System::Drawing::Size(36, 20);
			this->label_label_D0_context->TabIndex = 2;
			this->label_label_D0_context->Text = L"N/A";
			// 
			// panel44
			// 
			this->panel44->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel44->Controls->Add(this->label_match_point);
			this->panel44->Controls->Add(this->label_match_point_context);
			this->panel44->Location = System::Drawing::Point(22, 851);
			this->panel44->Name = L"panel44";
			this->panel44->Size = System::Drawing::Size(302, 29);
			this->panel44->TabIndex = 26;
			// 
			// label_match_point
			// 
			this->label_match_point->AutoSize = true;
			this->label_match_point->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_match_point->Location = System::Drawing::Point(3, 2);
			this->label_match_point->Name = L"label_match_point";
			this->label_match_point->Size = System::Drawing::Size(83, 20);
			this->label_match_point->TabIndex = 7;
			this->label_match_point->Text = L"MatchPoint";
			// 
			// label_match_point_context
			// 
			this->label_match_point_context->AutoSize = true;
			this->label_match_point_context->Font = (gcnew System::Drawing::Font(L"Microsoft MHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_match_point_context->Location = System::Drawing::Point(138, 2);
			this->label_match_point_context->Name = L"label_match_point_context";
			this->label_match_point_context->Size = System::Drawing::Size(36, 20);
			this->label_match_point_context->TabIndex = 2;
			this->label_match_point_context->Text = L"N/A";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1655, 882);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel_frame_count->ResumeLayout(false);
			this->panel_frame_count->PerformLayout();
			this->panel_frame->ResumeLayout(false);
			this->panel_frame->PerformLayout();
			this->panel_path->ResumeLayout(false);
			this->panel_path->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->panel41->ResumeLayout(false);
			this->panel41->PerformLayout();
			this->panel40->ResumeLayout(false);
			this->panel40->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->panel27->ResumeLayout(false);
			this->panel27->PerformLayout();
			this->panel33->ResumeLayout(false);
			this->panel33->PerformLayout();
			this->panel26->ResumeLayout(false);
			this->panel26->PerformLayout();
			this->panel34->ResumeLayout(false);
			this->panel34->PerformLayout();
			this->panel28->ResumeLayout(false);
			this->panel28->PerformLayout();
			this->panel35->ResumeLayout(false);
			this->panel35->PerformLayout();
			this->panel25->ResumeLayout(false);
			this->panel25->PerformLayout();
			this->panel36->ResumeLayout(false);
			this->panel36->PerformLayout();
			this->panel29->ResumeLayout(false);
			this->panel29->PerformLayout();
			this->panel24->ResumeLayout(false);
			this->panel24->PerformLayout();
			this->panel30->ResumeLayout(false);
			this->panel30->PerformLayout();
			this->panel23->ResumeLayout(false);
			this->panel23->PerformLayout();
			this->panel31->ResumeLayout(false);
			this->panel31->PerformLayout();
			this->panel22->ResumeLayout(false);
			this->panel22->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->panel43->ResumeLayout(false);
			this->panel43->PerformLayout();
			this->panel42->ResumeLayout(false);
			this->panel42->PerformLayout();
			this->panel38->ResumeLayout(false);
			this->panel38->PerformLayout();
			this->panel39->ResumeLayout(false);
			this->panel39->PerformLayout();
			this->panel32->ResumeLayout(false);
			this->panel32->PerformLayout();
			this->panel21->ResumeLayout(false);
			this->panel21->PerformLayout();
			this->panel37->ResumeLayout(false);
			this->panel37->PerformLayout();
			this->panel20->ResumeLayout(false);
			this->panel20->PerformLayout();
			this->panel18->ResumeLayout(false);
			this->panel18->PerformLayout();
			this->panel17->ResumeLayout(false);
			this->panel17->PerformLayout();
			this->panel19->ResumeLayout(false);
			this->panel19->PerformLayout();
			this->panel16->ResumeLayout(false);
			this->panel16->PerformLayout();
			this->panel15->ResumeLayout(false);
			this->panel15->PerformLayout();
			this->panel12->ResumeLayout(false);
			this->panel12->PerformLayout();
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			this->panel13->ResumeLayout(false);
			this->panel13->PerformLayout();
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->panel14->ResumeLayout(false);
			this->panel14->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->panel44->ResumeLayout(false);
			this->panel44->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (comboBox1->Text == "")
		{
			MessageBox::Show(this, "Select Capture Mode", "Error!!");
		}
		if (button1->Text == "start")
		{
			if (comboBox1->Text == "Load from existed file")
			{
				if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					btn_load_mat->Enabled = true;
					label_label_matfile->Enabled = true;
					label_log_matfile->Enabled = true;
					label_label_matfile_context->Enabled = true;
					label_log_matfile_context->Enabled = true;

					lab_path_context->Text = folderBrowserDialog1->SelectedPath;
					//ShowFileList();
					result_load = FindMatFiles(folderBrowserDialog1->SelectedPath);
					SelectedFolder = System::IO::Path::GetFileName(folderBrowserDialog1->SelectedPath);
					label_selected_folder_context->Text = SelectedFolder;
					//SourceName = (char*)Marshal::StringToHGlobalAnsi(openFileDialog1->FileName).ToPointer();
					trackBar1->Enabled = false;
					btn_play->Enabled = false;
					button1->Text = "stop";
				}
				//folderBrowserDialog1->SelectedPath->;
			}
			else if (comboBox1->Text == "Output from a new video")
			{
				openFileDialog1->Filter = "AVI files (*.avi)|*.txt|All files (*.*)|*.*";
				openFileDialog1->FilterIndex = 2;
				openFileDialog1->RestoreDirectory = true;
				openFileDialog1->FileName = "";
				if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					video_load_flag = 1;
					btn_play->Enabled = true;
					trackBar1->Enabled = true;

					lab_path_context->Text = openFileDialog1->FileName;
					label_label_matfile->Enabled = false;
					label_log_matfile->Enabled = false;
					label_label_matfile_context->Enabled = false;
					label_log_matfile_context->Enabled = false;

					SourceName = (char*)Marshal::StringToHGlobalAnsi(openFileDialog1->FileName).ToPointer();
					capture = cvCaptureFromFile(SourceName);
					trackBar1->Minimum = 0;
					trackBar1->Maximum = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
					lab_frame_count_context->Text = "" + (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
					lab_frame_width_context->Text = "" + cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
					lab_frame_height_context->Text = "" + cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
					System::Drawing::Bitmap^ frame_load = gcnew System::Drawing::Bitmap((int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH), 
						(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT));
					
					button1->Text = "stop";
					//timer1->Start();
					//-- Label Array
					label_array = gcnew array<double, 3>(14, 2, (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT));


				}
			}
		}
		else if (button1->Text == "stop")
		{
			btn_load_mat->Enabled = false;
			button1->Text = "start";
			cvReleaseCapture(&capture);
			timer1->Stop();
			lab_path_context->Text = "";
			video_load_flag = 0;
			btn_play->Enabled = false;
			btn_jump_to->Enabled = false;
			btn_pause->Enabled = false;
		}

	}
private: System::Void ShowFileList()
{
	for each (String^ entry in System::IO::Directory::GetDirectories(folderBrowserDialog1->SelectedPath))
	{
		DisplayFileSystemInfoAttributes(gcnew System::IO::DirectoryInfo(entry));
	}
	for each (String^ entry in System::IO::Directory::GetFiles(folderBrowserDialog1->SelectedPath))
	{
		DisplayFileSystemInfoAttributes(gcnew System::IO::FileInfo(entry));
	}
}

private: System::Void DisplayFileSystemInfoAttributes(System::IO::FileSystemInfo^ fsi)
{
	//  Assume that this entry is a file.
	String^ entryType = "File";

	// Determine if entry is really a directory
	if ((fsi->Attributes & System::IO::FileAttributes::Directory) == System::IO::FileAttributes::Directory)
	{
		entryType = "Directory";
	}
	//  Show this entry's type, name, and creation date.
	listBox1->BeginUpdate();
	listBox1->Items->Add(String::Format("{0} entry {1} was created on {2:D}", entryType, fsi->FullName, fsi->CreationTime));
	listBox1->EndUpdate();
}

/*find default matfile in selected directory
	return 0 -> can't find log and label mat file
	return 1 -> can't find label mat file
	return 10 -> can't find log mat file
	return 11 -> find default mat file successfully*/
private: System::Int16 FindMatFiles(String^ Directory)
{
	String^ SelectedDirectory = System::IO::Path::GetFileName(Directory);
	String^ labelfile_temp;
	String^ logfile_temp;
	int result_find_label = 0, result_find_log = 0;
	int result;

	//label_selected_folder_context->Text = SelectedDirectory;
	for each (String^ entry in System::IO::Directory::GetFiles(Directory))
	{
		//DisplayFileSystemInfoAttributes(gcnew System::IO::FileInfo(entry));
		System::IO::FileInfo^ entryFile = gcnew System::IO::FileInfo(entry);
		String^ SelectedFile = System::IO::Path::GetFileName(entry);
		/*matching label mat file*/
		if (SelectedFile == String::Format("{0}.mat", SelectedDirectory))
		{
			result_find_label = 1;
			labelfile_temp = SelectedFile;
		}

		/*matching log mat file*/
		if (SelectedFile == "grab_log.mat")
		{
			result_find_log = 1;
			logfile_temp = SelectedFile;
		}
	}

	result = result_find_label * 10 + result_find_log;

	switch (result)
	{
	case 11:
		label_label_matfile_context->Text = labelfile_temp;
		label_log_matfile_context->Text = logfile_temp;
		break;
	case 10:
		label_label_matfile_context->Text = labelfile_temp;
		label_log_matfile_context->Text = "Not found";
		MessageBox::Show("Can't find log file", "Not Found", MessageBoxButtons::OK);
		break;
	case 1:
		label_label_matfile_context->Text = "Not found";
		label_log_matfile_context->Text = logfile_temp;
		MessageBox::Show("Can't find label file", "Not Found", MessageBoxButtons::OK);
	default:
		label_label_matfile_context->Text = "Not found";
		label_log_matfile_context->Text = "Not found";
		MessageBox::Show("Can't find log and label file", "Not Found", MessageBoxButtons::OK);
		break;
	}

	return result;
}

private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {

	cvSetCaptureProperty(capture,CV_CAP_PROP_POS_FRAMES,trackBar1->Value);
	if (video_status_flag == 0)
	{
		frame_render();
	}
}


private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

	try
	{
		frame_render();

		frame = cvQueryFrame(capture);

		if (frame != NULL)
		{

			pictureBox1->Image = gcnew System::Drawing::Bitmap(frame->width, frame->height, frame->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) frame->imageData);
			pictureBox1->Refresh();
			pictureBox2->Image = gcnew System::Drawing::Bitmap(frame->width, frame->height, frame->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) frame->imageData);
			pictureBox2->Refresh();

			lab_frame_context->Text = "" + (int)cvGetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES);
		}

		trackBar1->Value = cvGetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES);
	}
	catch (...){}

}

private: System::Void frame_render()
{
	frame = cvQueryFrame(capture);

	if (frame != NULL)
	{
		try
		{
			pictureBox1->Image = gcnew System::Drawing::Bitmap(frame->width, frame->height, frame->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) frame->imageData);
			pictureBox1->Refresh();
			pictureBox2->Image = gcnew System::Drawing::Bitmap(frame->width, frame->height, frame->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) frame->imageData);
			pictureBox2->Refresh();

			lab_frame_context->Text = "" + (int)cvGetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES);
		}
		catch (System::Exception^ e)
		{
			MessageBox::Show(gcnew System::String(e->GetType()->ToString() + " exception!!!"), "Run Time Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

private: int findstructure(
	const char *file,
	const char *arr,
	const char *field,
	int mattype,
	int fieldnumber
	) {

	MATFile *mfPtr; /* MAT-file pointer */
	mxArray *aPtr;  /* mxArray pointer */

	mfPtr = matOpen(file, "r");
	if (mfPtr == NULL) {
		printf("Error opening file %s\n", file);
		return(1);
	}

	aPtr = matGetVariable(mfPtr, arr);
	if (aPtr == NULL) {
		printf("mxArray not found: %s\n", arr);
		return(1);
	}

	/*detect mat file input type*/
	if (mattype == LOG) 
	{
		if (mxGetClassID(aPtr) == mxSTRUCT_CLASS) {
			if (mxGetFieldNumber(aPtr, field) == -1) {
				printf("Field not found: %s\n", field);
			}
			else {
				analyzestructarray_log(aPtr, field, fieldnumber);
			}
		}
		else {
			printf("%s is not a structure\n", arr);
		}
	}
	else if (mattype == LABEL)
	{
		if (mxGetClassID(aPtr) == mxSTRUCT_CLASS) {
			if (mxGetFieldNumber(aPtr, field) == -1) {
				printf("Field not found: %s\n", field);
			}
			else {
				analyzestructarray_label(aPtr, field);
			}
		}
		else {
			printf("%s is not a structure\n", arr);
		}
	}
	
	
	mxDestroyArray(aPtr);

	if (matClose(mfPtr) != 0) {
		printf("Error closing file %s\n", file);
		return(1);
	}
	return(0);
}

/* Analyze field FNAME in struct array SPTR. for log*/
private: static void analyzestructarray_log(const mxArray *sPtr, const char *fName, int fieldnumber)
{
	mwSize nElements;       /* number of elements in array */
	mwIndex eIdx;           /* element index */
	const mxArray *fPtr;    /* field pointer */
	
	nElements = (mwSize)mxGetNumberOfElements(sPtr);

	//nDim = mxGetNumberOfDimensions(pa1);

	printf("Element of struct array is: %d\n", nElements);

	for (eIdx = 0; eIdx < nElements; eIdx++) {
		if (fieldnumber == FEILD1)
		{
			fPtr = mxGetField(sPtr, eIdx, fName);
			dims_log1 = mxGetDimensions(fPtr);
			classid_log1 = mxGetClassID(fPtr);
			if ((fPtr != NULL)
				&& (classid_log1 == mxDOUBLE_CLASS)
				&& (!mxIsComplex(fPtr)))
			{
				mxData_log = (double*)mxGetData(fPtr);
			}
		}
		else if (fieldnumber == FEILD2)
		{
			fPtr = mxGetField(sPtr, eIdx, fName);
			dims_log2 = mxGetDimensions(fPtr);
			classid_log2 = mxGetClassID(fPtr);
			if ((fPtr != NULL)
				&& (classid_log2 == mxCHAR_CLASS)
				&& (!mxIsComplex(fPtr)))
			{
				mxData_log_video = mxGetChars(fPtr);
			}
		}
		
		printf("The field %s of %dth of labels is complex? %d\n", fName, eIdx + 1, mxIsComplex(fPtr));
	}
	//printf("Total for %s: %.2f\n", fName, total);
}



/* Analyze field FNAME in struct array SPTR. for label*/
private: static void analyzestructarray_label(const mxArray *sPtr, const char *fName)
{
	mwSize nElements;       /* number of elements in array */
	mwIndex eIdx;           /* element index */
	const mxArray *fPtr;    /* field pointer */

	nElements = (mwSize)mxGetNumberOfElements(sPtr);

	//nDim = mxGetNumberOfDimensions(pa1);

	printf("Element of struct array is: %d\n", nElements);

	for (eIdx = 0; eIdx < nElements; eIdx++) {

		fPtr = mxGetField(sPtr, eIdx, fName);
		dims_label = mxGetDimensions(fPtr);
		classid_label = mxGetClassID(fPtr);
		if ((fPtr != NULL)
			&& (classid_label == mxDOUBLE_CLASS)
			&& (!mxIsComplex(fPtr)))
		{
			mxData_label = (double*)mxGetData(fPtr);
		}

		printf("The field %s of %dth of labels is complex? %d\n", fName, eIdx + 1, mxIsComplex(fPtr));
	}
}


private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void btn_jump_to_Click(System::Object^  sender, System::EventArgs^  e) {

	/*cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, textBox_jump_to->Text);
	frame_render();*/
	
}
private: System::Void btn_edit_modify_Click(System::Object^  sender, System::EventArgs^  e) {
	edit_mode_label = 0;
	edit_mode_modify = 1;
	btn_edit_modify->FlatAppearance->BorderSize = 2;
	btn_edit_label->FlatAppearance->BorderSize = 1;
	flag_edit_modify = 1;
	flag_edit_label = 0;
	listBox1->Enabled = true;
	trackBar1->Enabled = false;
}
private: System::Void btn_preview_mode_Click(System::Object^  sender, System::EventArgs^  e) {

	btn_edit_label->Visible = false;
	btn_edit_modify->Visible = false;
	btn_edit_mode->Enabled = true;
	btn_edit_label->FlatAppearance->BorderSize = 1;
	btn_edit_modify->FlatAppearance->BorderSize = 1;
	flag_edit_label = 0;
	flag_edit_modify = 0;
	btn_preview_mode->Enabled = false;
	btn_load_mat->Enabled = true;
	trackBar1->Enabled = false;
	listBox1->Enabled = true;
}
private: System::Void btn_edit_label_Click(System::Object^  sender, System::EventArgs^  e) {
	edit_mode_label = 1;
	edit_mode_modify = 0;
	btn_edit_modify->FlatAppearance->BorderSize = 1;
	btn_edit_label->FlatAppearance->BorderSize = 2;
	flag_edit_label = 1;
	flag_edit_modify = 0;
	listBox1->Enabled = false;
	trackBar1->Enabled = true;
}
private: System::Void btn_edit_mode_Click(System::Object^  sender, System::EventArgs^  e) {
	btn_edit_label->Visible = true;
	btn_edit_modify->Visible = true;
	btn_preview_mode->Enabled = true;
	btn_edit_mode->Enabled = false;
	btn_load_mat->Enabled = false;
	listBox1->Enabled = false;
}
	private: System::Void edit_label()
	{
		System::Drawing::Bitmap^ frame_for_render = gcnew System::Drawing::Bitmap(frame->width, frame->height, frame->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) frame->imageData);
		
	}

private: System::Void pictureBox2_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Point^ label_position_temp = gcnew Point(e->X, e->Y);
	int getPoint;

	lab_label_x_context->Text = label_position_temp->X.ToString();
	lab_label_y_context->Text = label_position_temp->Y.ToString();

	if (flag_edit_modify)
	{
		getPoint = MatchingPoint(label_position_temp);
		label_match_point_context->Text = getPoint.ToString();
	}

}

private: int MatchingPoint(Point^ position)
{
	int labelNumbertemp, pointNumber;
	Point^ labelPoint;
	double ShowWidthScale = ((double)pictureBox2->Width / (double)pictureBox2->Image->Width),
		ShowHeightScale = ((double)pictureBox2->Height / (double)pictureBox2->Image->Height);

	/*scan point number*/
	for (size_t labelNumbertemp = 0; labelNumbertemp < dims_label[0]; labelNumbertemp)
	{
		/*scan area of point*/
		for (int i = 0; i < 7; i++)
		{
			for (int j = 1; j < 7; j++)
			{
				labelPoint = gcnew System::Drawing::Point((double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 0 + labelNumbertemp] * ShowWidthScale - 3.0 + i,
					(double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 1 + labelNumbertemp] * ShowHeightScale - 3.0 + j);
				if ((labelPoint->X == position->X) && (labelPoint->Y == position->Y))
				{
					pointNumber = labelNumbertemp + 1;
				}
			}
		}
	}
	return pointNumber;
}

private: System::Void btn_play_Click(System::Object^  sender, System::EventArgs^  e) {
	if (video_load_flag == 1)
	{
		if (video_status_flag == 0)
		{
			video_status_flag = 1;
			timer1->Start();
			btn_play->Enabled = false;
			btn_pause->Enabled = true;
			btn_jump_to->Enabled = false;
			btn_edit_mode->Enabled = false;
		}

	}
}
private: System::Void btn_pause_Click(System::Object^  sender, System::EventArgs^  e) {
	if (video_status_flag == 1)
	{
		video_status_flag = 0;
		timer1->Stop();
		btn_play->Enabled = true;
		btn_pause->Enabled = false;
		btn_jump_to->Enabled = true;
		btn_edit_mode->Enabled = true;

	}
}
private: System::Void btn_load_mat_Click(System::Object^  sender, System::EventArgs^  e) {
	if (button1->Text == "stop")
	{
		btn_load_mat->Text = "reload";
		btn_edit_mode->Enabled = true;

		if (result_load == 11)
		{
			LoadMatFile();
		}
	}
}

private: System::Void LoadMatFile()
{
	result_label = findstructure((char*)Marshal::StringToHGlobalAnsi(String::Format("{0}\\{1}", lab_path_context->Text, label_label_matfile_context->Text)).ToPointer(),
		label_parameterName, label_field1, LABEL, FEILD1);
	result_log = findstructure((char*)Marshal::StringToHGlobalAnsi(String::Format("{0}\\{1}", lab_path_context->Text, label_log_matfile_context->Text)).ToPointer(),
		log_parameterName, log_field1, LOG, FEILD1);
	result_inputVideo = findstructure((char*)Marshal::StringToHGlobalAnsi(String::Format("{0}\\{1}", lab_path_context->Text, label_log_matfile_context->Text)).ToPointer(),
		log_parameterName, log_field2, LOG, FEILD2);

	label_result_label_context->Text = result_label.ToString();
	label_result_log_context->Text = result_log.ToString();
	label_result_log2_context->Text = result_inputVideo.ToString();

	if (!result_label)
	{
		label_label_D0_context->Text = dims_label[0].ToString();
		label_label_D1_context->Text = dims_label[1].ToString();
		label_label_D2_context->Text = dims_label[2].ToString();
	}
	else
	{
		label_label_D0_context->Text = "load error";
		label_label_D1_context->Text = "load error";
		label_label_D2_context->Text = "load error";
	}
	if (!result_log)
	{
		label_log_D0_context->Text = dims_log1[0].ToString();
		label_log_D1_context->Text = dims_log1[1].ToString();
		label_log_D2_context->Text = dims_log1[2].ToString();
	}
	else
	{
		label_log_D0_context->Text = "load error";
		label_log_D1_context->Text = "load error";
		label_log_D2_context->Text = "load error";
	}
	listBox1->Items->Clear();
	listBox1->BeginUpdate();

	/*if ((dims_label[0] == 14) && (dims_label[1] == 2))
	{
		for (z_label = 0; z_label < dims_label[2]; z_label++)
		{
			for (row_label = 0; row_label < dims_label[0]; row_label++)
			{
				listBox1->Items->Add(String::Format("Frame No.{0} label {1} is: {2} {3}", z_label + 1, row_label + 1,
					mxData_label[dims_label[0] * dims_label[1] * z_label + dims_label[0] * 0 + row_label],
					mxData_label[dims_label[0] * dims_label[1] * z_label + dims_label[0] * 1 + row_label]));
			}
		}
	}*/

	for (int x = 1; x <= dims_log1[1]; x++)
	{
		listBox1->Items->Add(String::Format("Data No.{0} is: Frame No.{1}", x, mxData_log[x - 1]));
	}
	listBox1->EndUpdate();

	capture = cvCaptureFromFile((char*)Marshal::StringToHGlobalAnsi(String::Format("{0}\\{1}", lab_path_context->Text, gcnew String(mxData_log_video))).ToPointer());
	trackBar1->Minimum = 0;
	trackBar1->Maximum = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
	lab_frame_count_context->Text = "" + (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
	lab_frame_width_context->Text = "" + cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
	lab_frame_height_context->Text = "" + cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
	System::Drawing::Bitmap^ frame_load = gcnew System::Drawing::Bitmap((int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH),
		(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT));
}

private: System::Void listBox1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	index = this->listBox1->IndexFromPoint(e->Location);
	int frameNumber = mxData_log[index];
	
	label_ListBox_Index_context->Text = index.ToString();

	cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, frameNumber-1);
	trackBar1->Value = frameNumber-1;
	frame_render();

	LabelPrintOn(index);
}

/*print out label location*/
private: System::Void LabelPrintOn(int index)
{
	g->Clear(System::Drawing::Color::Transparent);
	pictureBox2->Image = gcnew System::Drawing::Bitmap(frame->width, frame->height, frame->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) frame->imageData);
	pictureBox2->Refresh();

	if (index > dims_label[2])
	{
		MessageBox::Show(this, "Out of Data Range", "Error!!");
	}
	else
	{
		double PrintWidthScale = ((double)pictureBox2->Width / (double)pictureBox2->Image->Width) * 1.25;
		double PrintHeightScale = ((double)pictureBox2->Height / (double)pictureBox2->Image->Height) * 1.25;
		double ShowWidthScale = PrintWidthScale / 1.25;
		double ShowHeightScale = PrintHeightScale / 1.25;

		label_picBox2_ImgW_context->Text = pictureBox2->Image->Width.ToString();
		label_picBox2_ImgH_context->Text = pictureBox2->Image->Height.ToString();

		label_Width_Scale_context->Text = ShowWidthScale.ToString();
		label_Height_Scale_context->Text = ShowHeightScale.ToString();

		label_Read_Coord_X_context->Text = mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 0 + 0].ToString();
		label_Read_Coord_Y_context->Text = mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 1 + 0].ToString();

		System::Drawing::Size *labelPointSize = new System::Drawing::Size(6, 6);
		System::Drawing::Point *labelPoint, *labelPointPrintCoord, *labelPointTemp1, *labelPointTemp2;
		System::Drawing::Point *labelBodyPoint1, *labelBodyPoint2, *labelBodyPoint3, *labelBodyPoint4, *labelBodyPoint5;

		int labelNumber;

		int partion;

		/*print label point*/
		for (size_t labelNumber = 0; labelNumber < 14; labelNumber++)
		{
			labelPoint = new System::Drawing::Point((double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 0 + labelNumber] * ShowWidthScale,
				(double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 1 + labelNumber] * ShowHeightScale);

			labelPointPrintCoord = new System::Drawing::Point((double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 0 + labelNumber] * ShowWidthScale - 3.0 ,
				(double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 1 + labelNumber] * ShowHeightScale -3.0 );

			partion = labelNumber % 3;

			switch (labelNumber / 3)
			{
			case 0:		//labelNumber = 0~2 : right leg

				g->FillEllipse(System::Drawing::Brushes::Red, System::Drawing::Rectangle(*labelPointPrintCoord, *labelPointSize));


				if (partion == 0)  label_label_P1_context->Text = String::Format("X:{0}       Y:{1}", (double)labelPoint->X, (double)labelPoint->Y);
				if (partion == 1)  label_label_P2_context->Text = String::Format("X:{0}       Y:{1}", (double)labelPoint->X, (double)labelPoint->Y);
				if (partion == 2)  label_label_P3_context->Text = String::Format("X:{0}       Y:{1}", (double)labelPoint->X, (double)labelPoint->Y);

				break;
			case 1:		//labelNumber = 3~5 : left leg
				g->FillEllipse(System::Drawing::Brushes::Blue, System::Drawing::Rectangle(*labelPointPrintCoord, *labelPointSize));

				if (partion == 0)  label_label_P4_context->Text = String::Format("X:{0}       Y:{1}", labelPoint->X, labelPoint->Y);
				if (partion == 1)  label_label_P5_context->Text = String::Format("X:{0}       Y:{1}", labelPoint->X, labelPoint->Y);
				if (partion == 2)  label_label_P6_context->Text = String::Format("X:{0}       Y:{1}", labelPoint->X, labelPoint->Y);

				break;
			case 2:		//labelNumber = 6~8	: right arm
				g->FillEllipse(System::Drawing::Brushes::Magenta, System::Drawing::Rectangle(*labelPointPrintCoord, *labelPointSize));

				if (partion == 0)  label_label_P7_context->Text = String::Format("X:{0}       Y:{1}", labelPoint->X, labelPoint->Y);
				if (partion == 1)  label_label_P8_context->Text = String::Format("X:{0}       Y:{1}", labelPoint->X, labelPoint->Y);
				if (partion == 2)  label_label_P9_context->Text = String::Format("X:{0}       Y:{1}", labelPoint->X, labelPoint->Y);

				break;
			case 3:		//labelNumber = 9~11 : left arm
				g->FillEllipse(System::Drawing::Brushes::Cyan, System::Drawing::Rectangle(*labelPointPrintCoord, *labelPointSize));

				if (partion == 0)  label_label_P10_context->Text = String::Format("X:{0}       Y:{1}", labelPoint->X, labelPoint->Y);
				if (partion == 1)  label_label_P11_context->Text = String::Format("X:{0}       Y:{1}", labelPoint->X, labelPoint->Y);
				if (partion == 2)  label_label_P12_context->Text = String::Format("X:{0}       Y:{1}", labelPoint->X, labelPoint->Y);

				break;
			case 4:		//labelNumber = 12~13 : top 
				g->FillEllipse(System::Drawing::Brushes::Green, System::Drawing::Rectangle(*labelPointPrintCoord, *labelPointSize));

				if (partion == 0)  label_label_P13_context->Text = String::Format("X:{0}       Y:{1}", labelPoint->X, labelPoint->Y);
				if (partion == 1)  label_label_P14_context->Text = String::Format("X:{0}       Y:{1}", labelPoint->X, labelPoint->Y);

				break;
			default:
				break;
			}
		}

		System::Drawing::Pen^ SkeletonPen;
		/*print skeleton*/
		if (chkBox_skeletonize_state->Checked)
		{
			/*print limbs*/
			for (labelNumber = 0; labelNumber < 13; labelNumber++)
			{
				labelPointTemp1 = new System::Drawing::Point((double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 0 + labelNumber] * ShowWidthScale,
					(double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 1 + labelNumber] * ShowHeightScale);
				labelPointTemp2 = new System::Drawing::Point((double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 0 + labelNumber + 1] * ShowWidthScale,
					(double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 1 + labelNumber + 1] * ShowHeightScale);

				if ( (labelNumber + 1)%3 != 0)
				{
					switch (labelNumber/3)
					{
					case 0:
						SkeletonPen = gcnew Pen(System::Drawing::Color::Red, 2);
						g->DrawLine(SkeletonPen, *labelPointTemp1, *labelPointTemp2);
						break;
					case 1:
						SkeletonPen = gcnew Pen(System::Drawing::Color::Blue, 2);
						g->DrawLine(SkeletonPen, *labelPointTemp1, *labelPointTemp2);
						break;
					case 2:
						SkeletonPen = gcnew Pen(System::Drawing::Color::Magenta, 2);
						g->DrawLine(SkeletonPen, *labelPointTemp1, *labelPointTemp2);
						break;
					case 3:
						SkeletonPen = gcnew Pen(System::Drawing::Color::Cyan, 2);
						g->DrawLine(SkeletonPen, *labelPointTemp1, *labelPointTemp2);
						break;
					case 4:
						SkeletonPen = gcnew Pen(System::Drawing::Color::Green, 2);
						g->DrawLine(SkeletonPen, *labelPointTemp1, *labelPointTemp2);
						break;
					default:
						break;
					}

				}
			}

			/*print body*/
			labelBodyPoint1 = new System::Drawing::Point((double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 0 + 2] * ShowWidthScale,
				(double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 1 + 2] * ShowHeightScale);
			labelBodyPoint2 = new System::Drawing::Point((double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 0 + 8] * ShowWidthScale,
				(double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 1 + 8] * ShowHeightScale);
			labelBodyPoint3 = new System::Drawing::Point((double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 0 + 12] * ShowWidthScale,
				(double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 1 + 12] * ShowHeightScale);
			labelBodyPoint4 = new System::Drawing::Point((double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 0 + 9] * ShowWidthScale,
				(double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 1 + 9] * ShowHeightScale);
			labelBodyPoint5 = new System::Drawing::Point((double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 0 + 3] * ShowWidthScale,
				(double)mxData_label[dims_label[0] * dims_label[1] * index + dims_label[0] * 1 + 3] * ShowHeightScale);
			SkeletonPen = gcnew Pen(System::Drawing::Color::Yellow, 2);
			g->DrawLine(SkeletonPen, *labelBodyPoint1, *labelBodyPoint2);
			g->DrawLine(SkeletonPen, *labelBodyPoint2, *labelBodyPoint3);
			g->DrawLine(SkeletonPen, *labelBodyPoint3, *labelBodyPoint4);
			g->DrawLine(SkeletonPen, *labelBodyPoint4, *labelBodyPoint5);

		}
	}
	
}
private: System::Void btn_clean_mat_Click(System::Object^  sender, System::EventArgs^  e) {
	listBox1->Items->Clear();
}

private: System::Void btn_DEBUG_refresh_Click(System::Object^  sender, System::EventArgs^  e) {
	label_picBox1_W_context->Text = pictureBox1->Width.ToString();
	label_picBox1_H_context->Text = pictureBox1->Height.ToString();
	label_picBox2_W_context->Text = pictureBox2->Width.ToString();
	label_picBox2_H_context->Text = pictureBox2->Height.ToString();
}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	LabelPrintOn(index);
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox2_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	//Point^ label_position_temp = gcnew Point(, e->Y);
}
};
}
