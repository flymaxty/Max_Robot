#ifndef FuzzyController_h
#define FuzzyController_h

//FuzzyControllerV1.0
//by socoolzjm
class FuzzyController
{
	private:
		int inputEMin, inputEMax;
		int discreteExMin, discreteExMax, discreteUMin, discreteUMax;
		float Ke;
		float Kec;
		float Ku;

		unsigned int inputDiscreteVariableNum;
		unsigned int outputDiscreteVariableNum;
		static const unsigned int fuzzySetNum;
		int inputMagnification;
		int outputMagnification;
		float **fuzzyRelationMatrix;

		static const unsigned int fuzzyRuler[7][7];
		float **fuzzyResponseSheet;

		struct fuzzyVariableSheet
		{
			float discreteVariable;
			unsigned int fuzzySet;
			float memberShipDegree;
		}**exfuzzyVariableSheet, **ecxfuzzyVariableSheet, **uxfuzzyVariableSheet;

		void InputFuzzySubsetGenerate(int min, int max, int magnification);
		void OutputFuzzySubsetGenerate(int min, int max, int magnification);
		float InputMemberShipFunction(unsigned int languageLevel, float subsetInput);
		float OutputMemberShipFunction(unsigned int languageLevel, float subsetInput);
		float TriangularMembershipFunction(float variable, float a, float b, float c);
		unsigned int FuzzificationFunction(float input, int inputMin, int inputMax, float K, fuzzyVariableSheet **variableSheet);
		fuzzyVariableSheet *FuzzyInference(unsigned int discreteVariableERowPosition, unsigned int inputVariableENum, fuzzyVariableSheet **variableESheet,
			unsigned int discreteVariableEcRowPosition, unsigned int inputVariableEcNum, fuzzyVariableSheet **variableEcSheet,
			unsigned int outputVariableUNum, fuzzyVariableSheet **variableUSheet,
			unsigned int fuzzySetNum);
		void FuzzyResponseSheetGenerate(unsigned int inputVariableENum, fuzzyVariableSheet **variableESheet,
			unsigned int inputVariableEcNum, fuzzyVariableSheet **variableEcSheet,
			unsigned int outputVariableUNum, fuzzyVariableSheet **variableUSheet,
			unsigned int fuzzySetNum);
		void DisplayfuzzyVariableSheet(fuzzyVariableSheet **variableSheet, unsigned int SheetColNum, unsigned int SheetRowNum);
		float Defuzzification(fuzzyVariableSheet *fuzzyOutputVariable, unsigned int outputVariableUNum, unsigned int method);

	public:
		//ģ����������ʼ������
		FuzzyController(void);
		void FuzzyControllerInitialize(int discreteExMinValue, int discreteExMaxValue, int inputMagnificationValue,//�����仯��Ҳ�������ֵ����ɢ��Сֵ���������Ⱥ����йأ�Ҫ��һ��ģ�������Ĭ��ֵ���������仯��Ҳ�������ֵ����ɢ���ֵ���������Ⱥ����йأ�Ҫ��һ��ģ�������Ĭ��ֵ������ɢֵ��ȡֵ������Խ��Խ����Խ��ϸ����ʼ���ٶ�Խ����
			int discreteUMinValue, int discreteUMaxValue, int outputMagnificationValue,//��������仯��Ҳ�������ֵ����ɢ��Сֵ���������Ⱥ����йأ�Ҫ��һ��ģ�������Ĭ��ֵ������������仯��Ҳ�������ֵ����ɢ���ֵ���������Ⱥ����йأ�Ҫ��һ��ģ�������Ĭ��ֵ������ɢֵ��ȡֵ������Խ��Խ����Խ��ϸ����ʼ���ٶ�Խ����
			int inputEMinValue, int inputEMaxValue,//ʵ����ʵ�����仯��Ҳ�������ֵ���������Сֵ����ŷ�Χ����ʵ����ʵ�����仯��Ҳ�������ֵ������������ֵ����ŷ�Χ��
			float KeValue, float KecValue, float KuValue); //����������ӣ����仯���������ӣ�����ı�������
		//�����������������float��
		float FuzzyControlOutput(float inputE, float inputEc);//�������������Ĳ�ֵ
};

#endif //Debug_Display_h
