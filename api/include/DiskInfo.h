/**
 * class for DiskInfo's data
 */
class DiskInfoData {
public:
    string vender;			//!< Device vendor
    string model;           //!< Device model
    string serial;          //!< Device serial number
    int size;            	//!< Device total size
    int size_sdx2;       	//!< Device partition 2 size
};

/**
 * class for schedule data of S.M.A.R.T test.
 */
class SmartTestScheduleData {
public:
    int type;				//!< 1 is Monthly, 2 is Weekly, 3 is Daily
    int hour;           	//!< 0~24
    int minute;          	//!< 0~59
    int weekly;            	//!< 0~6, 0 is Sunday.
};

//! class DiskInfo.
/**
 *
 */
class DiskInfo
{

public:
    /**
     * Constructs DiskInfo with specific disk node.
     * Initialize m_pData.
     * @param devnode specific device node. /dev/sda is 0.
     */
    DiskInfo(int devnode);

    /**
     * Destory DiskInfo.
     * Delete m_pData.
     */
    virtual ~DiskInfo();

    //! The static function will get how many disks now in Nas.
    /**
     * @return Returns how many disks. The value should be 0/1/2/-1.
     * Returns -1 if errors happen.
     */
    static int getDiskNum();

//    //! The static function will get proress info for formating a disk.
//    /**
//     * @param percent store percentage of formating disk.
//     * @param describe store device number. sda is 1 and adb is 2, etc..
//     * @param errcode ?
//     * @return Returns 1 if success. Return 0 if fail.
//     */
//    static int getDiskFMTProgress(int &percent int &describe, int &errcode);

    //! The static function will create S.M.A.R.T test list and send mail.
    /**
     * @param smartmail ?.
     * @return Returns 0 if sending mail success.
     */
    static int createSmartTestList(int &smartmail);

    //! The static function will get schedule of S.M.A.R.T test.
    /**
     * @return the data of schedule.
     */
    static SmartTestScheduleData getSmartTestSchedule(int devnode);

    //! The static function will set schedule of S.M.A.R.T test.
    /**
     * @param data schedule data.
     * @param devnode specific device node. /dev/sda is 0.
     * @return Returns 1 if success. Return 0 if fail.
     */
    static int setSmartTestSchedule(SmartTestScheduleData data, int devnode);

    //! The static function will set to delete schedule of S.M.A.R.T test.
    /**
     * @param devnode specific device node. /dev/sda is 0.
     * @return Returns 1 if success. Return 0 if fail.
     */
    static int setDelteSmartTestSchedule(int devnode);

    //! The static function will set to start S.M.A.R.T test.
    /**
     * @param devnode specific device node. /dev/sda is 0.
     * @return Returns 1 if success. Return 0 if fail.
     */
    static int setStartSmartTest(int devnode);

    //! The static function will get S.M.A.R.T test status.
    /**
     * @param devnode specific device node. /dev/sda is 0.
     * @return Returns 0.
     */
    static int getSmartTestStatus(int devnode);

    //! The static function will set disk scan.
    /**
     * @param devnode specific device node. /dev/sda is 0.
     * @return Returns 1 if success. Return 0 if fail.
     */
    static int setDiskScan(int devnode);

    //! The static function will set disk scan finish.
    /**
     * @param devnode specific device node. /dev/sda is 0.
     * @return Returns 1 if success. Return 0 if fail.
     */
    static int setDiskScanFinish(int devnode);

    //! The function will get disk info data.
    /**
     * Get physical device info. by specific disk node.
     * @param data store disk info.
     * @param devnode specific device node. /dev/sda is 0.
     * @return Returns 1 if success. Return 0 if fail.
     */
    int getDiskInfo(DiskInfoData &data, int devnode);

private:
    DiskInfoData *m_pData; //!< Store data of an disk.

};
