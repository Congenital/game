//
//  MiniSupport.h
//  TRGame
//
//  Created by Long on 17/3/7.
//
//

#ifndef MiniSupport_h
#define MiniSupport_h
#include "cocos2d.h"
#include "network/CCDownloader.h"
#include "Image.h"
USING_NS_CC;
/************************************************************************/
/* ��ʱ֧��png,jpg
*/
/************************************************************************/
class MiniSupport 
{
public:
	//ReadSpriteName�ӿ�ʹ�õ�ͼƬ֧�ָ�������
	static Sprite* makeRemoteSprite(const char* imgFile, Sprite* sp);

	//ChessReadFile�ӿ�ʹ�õ�TRImage֧�ָ�������
	static void checkMiniTRImagePtr(const char *filename, int is_writeable, int is_globe);

	//����ͼ�Ƿ���Ҫ��������
	static void checkMiniTRPacketImage(const char *filename, int is_writeable, int is_globe);


	//�ļ���׺�Ƿ�֧��
	static bool isMiniSupportExt(const char* fileName);

	//����ļ��Ƿ���������
	static bool isDownloading(const char* fileName, int is_writeable = 0, int is_globe = 1);

	//�Ž��������ʵʱˢ��֪ͨ�б�
	static void pushPtr(const char* key, TRImagePtr imagePtr);

	//���������ʵʱˢ��֪ͨ�б����Ƴ�
	static void popPtr(const char* key);

	//ˢ��TRImagePtr
	static void doRefreshTRImagePtr(const char* key);



	MiniSupport() { assert(false && "do not alloc me"); };
	//��ʼ��һ��
	static void initWithPath(const std::string& gamePath, const std::string& writeAblePath);
	//worker ����
	static void Destroy();
};

class MiniImgDownloadWorker
{
public:
	virtual bool init();
	void downloadFile(const char* file, int is_writeable = 0, int is_globe = 1);
	const char* getDownloadUrl(const char* file, int is_writeable = 0, int is_globe = 1);
	//����ļ��Ƿ���������
	bool isDownloading(const char* file, int is_writeable = 0, int is_globe = 1);
private:
	FileUtils * fileUtils;
	std::string miniPatchDir;
	std::string downloadMiniPatchUrlBase;
	std::shared_ptr<network::Downloader> fileDownloader;
};

class TrImageRefreshWorker
{
	typedef std::map<std::string, TRImagePtr> TRImagePtrMap;
	typedef TRImagePtrMap::iterator TRPMapI;
public:
	void pushPtr(const char* key, TRImagePtr imagePtr);
	void popPtr(const char* key);
	//ˢ��TRImagePtr
	void doRefreshTRImagePtr(const char* key);
	virtual bool init();
private:
	TRImagePtrMap imagePtrMap;

};
#endif /* MiniSupport_h */
