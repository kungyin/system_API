/**
 * An enum type RAIDMODE.
 */
enum RAIDMODE{
	eStandard = 0,
	eLinear,
	eRaid0,
	eRaid1
};

/**
 * class for DiskVol's data
 */
class DiskVolData {
public:
	RAIDMODE raid_mode;   	//!< value will be eStandard/eLinear/eRaid0/eRaid1.
	string file_type;		//!< file_type will be "ext4" now.
	int size;				//!< size in bytes
	int used_size;			//!< size in bytes
	int free_size;			//!< size in bytes
	int device_node;		//!< sda is 0, sdb is 1
	string mount_point;		//!< ex. /dev/sda2 | /dev/sdb2
	int encrypt;			//!< 0: no encrypt, 1: encrypt
	int mount_status;		//!< mount status is 1
	//string scsi_mapping;
	int raid_uuid;			//!< Raid UUID number
	//int is_roaming_vol;
	//string scsi0_serial;
	//string scsi2_serial;
};

//! class DiskVol.
/**
 *
 */
class DiskVol
{

public:
    /**
     * Constructs DiskVol.
     * Initialize m_pData.
     */
	DiskVol();

    /**
     * Destory DiskInfo.
     * Delete m_pData.
     */
    virtual ~DiskInfo();

    //! The static function will get how many volumes now in Nas.
    /**
     * @return Returns how many volumes. The value should be 0/1/2/-1.
     * Returns -1 if errors happen.
     */
    static int getDiskVolNum();

    //! The static function will get disk volume status.
    /**
     * @return
     * 0 -> no volume\n
	 * 1 -> volume is ok\n
	 * 2 -> S.M.A.R.T. Test now\n
	 * 3 -> Formating now\n
	 * 4 -> Scaning Disk\n
	 * 5 -> no disk\n
	 * 6 -> disks sequence are not valid.
     */
    static int getDiskVolumeStatus();

    //! The static function will get RAID sync value.
    /**
     * @return
     * 0 -> no sync.\n
	 * 1 -> sync now or wait sync.
     */
    static int getDiskRaidSync();

    //! The static function will get auto-rebuild configuration.
    /**
     * @return
     * 0 -> Disable Auto-Rebuild.\n
	 * 1 -> Enable Auto-Rebuild.
     */
    static int getAutoRebuildConf();

    //! The function will get disk volume data.
    /**
     * Get disk volume data by specific volume number.
     * @param data store disk volume data.
     * @param devnode specific volume number.
     * @return Returns 1 if success. Return 0 if fail.
     */
    int getDiskVolume(DiskVolData &data, int volume);

private:
    DiskInfoData *m_pData; //!< Store data of an disk.

};
