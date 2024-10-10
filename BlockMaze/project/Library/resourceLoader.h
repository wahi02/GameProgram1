#pragma once
#include <string>

namespace ResourceLoader {
	void Init();
	int LoadGraph(std::string filename);
	void DeleteGraph(int handle);
	int MV1LoadModel(std::string filename);
	void MV1DeleteModel(int handle);
	int LoadSoundMem(std::string filename);
	void DeleteSoundMem(int handle);
	void LoadFolderFile(std::string folder, bool loadSubFolder=false);

	/// <summary>
	/// �񓯊��ǂݍ��݂����邩��ݒ肷��
	/// </summary>
	/// <param name="async">�񓯊��ǂݍ��݂���ꍇtrue</param>
	void SetAsync(bool async);

	/// <summary>
	/// �񓯊��Ńt�@�C����ǂ�ł��邩
	/// </summary>
	/// <returns>�t�@�C����ǂ�ł���r����true</returns>
	bool IsLoading();

	/// <summary>
	/// �ǂ񂾃t�@�C����S������
	/// </summary>
	void ReleaseAllFile();
};