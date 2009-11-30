#ifndef SEQUENCE_H_
#define SEQUENCE_H_
#include <vector>
#include "math.h"
#include <string>
using namespace std;

#define DATATYPE float
void chompstr(char* line);
int count_line(const char* file);
int count_column(char* line, char delim);
char* getnextstring(char* pstart, char* buffer, char delim);

class CSequence
{
public:
    CSequence();
    CSequence(const CSequence& seq);
    ~CSequence();
    int Allocate(int nPoint, int nFeatureDim);
    void Release();
    void SetPointValue(int iPoint, DATATYPE* vFeature);
    DATATYPE* GetPoint(int iIndex);

//data
public: 
    int m_iFeatureDim;
    int m_iPoint;
    DATATYPE** m_vFeature;
    DATATYPE* m_vX;
    DATATYPE* m_vY;
    int m_iID;

// for chopped sequence
    int m_iOriginalSeqId; 
    int m_iStartPos;
};

class CSetOfSeq
{

public:
    CSetOfSeq();
    CSetOfSeq(const CSetOfSeq& ss);
    ~CSetOfSeq();
    int AddSequence(CSequence* pSeq);
    int LoadSS(const char* strFile);
    int LoadSSBinary(const char* strFile);
    int SaveSSBinary(const char* strFile);

    int CheckSeq(const char* strFile);
    void Print();
    void Update();
    void Release();
    int SplitSeq(int iSeqIndex, int iSplitPos1, int iSplitPos2);
    int SplitSeqByID(int iSeqID, int iSplitPos1, int iSplitPos2);
    int RemoveShortSeqs(int iMinLen);


//Data
public:    
    int m_iSeqNum;
    int m_iFeatureDim;
    int m_iTotalPoint;
    vector<CSequence*> m_vSeqs;
    vector<int> m_vSeqLength;
    string m_strFileName;
    int m_iShapeID;
    int m_iClassID;
    int m_iSeqIds;
};
#endif