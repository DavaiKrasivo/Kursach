//#include "MyForm.h" //the header name for your form
//
//using namespace WinForm; // WinForm - name of your project
//
//[STAThreadAttribute]
//int main(array<System::String ^> ^args)
//{
//	Application::EnableVisualStyles();
//	Application::SetCompatibleTextRenderingDefault(false);
//
//	Application::Run(gcnew MyForm());
//	return 0;
//}
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	WinForm::MyForm form;   //WinForm - name of your project
	Application::Run(%form);
}