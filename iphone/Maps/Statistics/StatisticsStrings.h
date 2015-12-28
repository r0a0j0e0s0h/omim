static NSString * const kStatAPI = @"API";
static NSString * const kStatAbout = @"About";
static NSString * const kStatAction = @"Action";
static NSString * const kStatActionSheet = @"Action sheet";
static NSString * const kStatAd = @"Ad";
static NSString * const kStatAdd = @"Add";
static NSString * const kStatAdTitle = @"Ad title";
static NSString * const kStatAlert = @"Alert";
static NSString * const kStatApplication = @"Application";
static NSString * const kStatApply = @"Apply";
static NSString * const kStatAuthorization = @"Authorization";
static NSString * const kStatBack = @"Back";
static NSString * const kStatBannerDescription = @"Banner description";
static NSString * const kStatBannerTitle = @"Banner title";
static NSString * const kStatBookmarks = @"Bookmarks";
static NSString * const kStatBuildRoute = @"Build route";
static NSString * const kStatButton = @"Button";
static NSString * const kStatCallPhoneNumber = @"Call phone number";
static NSString * const kStatCancel = @"Cancel";
static NSString * const kStatCategories = @"Categories";
static NSString * const kStatChangeBookmarkColor = @"Change bookmark color";
static NSString * const kStatChangeBookmarkDescription = @"Change bookmark description";
static NSString * const kStatChangeBookmarkGroup = @"Change bookmark group";
static NSString * const kStatChangeLanguage = @"Change language";
static NSString * const kStatChangeMeasureUnits = @"Change measure units";
static NSString * const kStatChangeRoutingMode = @"Change routing mode";
static NSString * const kStatClear = @"Clear";
static NSString * const kStatClose = @"Close";
static NSString * const kStatCollapse = @"Collapse";
static NSString * const kStatCompass = @"Compass";
static NSString * const kStatConnection = @"Connection";
static NSString * const kStatCopyright = @"Copyright";
static NSString * const kStatCountry = @"Country";
static NSString * const kStatDestination = @"Destination";
static NSString * const kStatDeviceInfo = @"Device info";
static NSString * const kStatDeviceType = @"Device type";
static NSString * const kStatDownloadAll = @"Download all";
static NSString * const kStatDownloadMap = @"Download map";
static NSString * const kStatDownloadMaps = @"Download maps";
static NSString * const kStatDownloaderDialog = @"Downloader dialog";
static NSString * const kStatDownloadRequest = @"Download request";
static NSString * const kStatDownloadRoute = @"Download route";
static NSString * const kStatEdit = @"Edit";
static NSString * const kStatEditTime = @"Edit time";
static NSString * const kStatExpand = @"Expand";
static NSString * const kStatExpandCategory = @"Expand category";
static NSString * const kStatExpandLargeCountry = @"Expand large country";
static NSString * const kStatExport = @"Export";
static NSString * const kStatFromMyPosition = @"From my position";
static NSString * const kStatGo = @"Go";
static NSString * const kStatHelp = @"Help";
static NSString * const kStatHidden = @"Hidden";
static NSString * const kStatHistory = @"History";
static NSString * const kStatImport = @"Import";
static NSString * const kStatIn = @"In";
static NSString * const kStatKML = @"KML";
static NSString * const kStatKilometers = @"Kilometers";
static NSString * const kStatLandscape = @"Landscape";
static NSString * const kStatLanguage = @"Language";
static NSString * const kStatLocation = @"Location";
static NSString * const kStatMap = @"Map search";
static NSString * const kStatMenu = @"Menu";
static NSString * const kStatMiles = @"Miles";
static NSString * const kStatMoreApps = @"More apps";
static NSString * const kStatMyPosition = @"My position";
static NSString * const kStatName = @"Name";
static NSString * const kStatNavigationDashboard = @"Navigation dashboard";
static NSString * const kStatNext = @"Next";
static NSString * const kStatNo = @"No";
static NSString * const kStatOff = @"Off";
static NSString * const kStatOn = @"On";
static NSString * const kStatOpen = @"Open";
static NSString * const kStatOpenActionSheet = @"Open action sheet";
static NSString * const kStatOpenSite = @"Open site";
static NSString * const kStatOrientation = @"Orientation";
static NSString * const kStatOther = @"Other";
static NSString * const kStatOut = @"Out";
static NSString * const kStatPedestrian = @"Pedestrian";
static NSString * const kStatPlacePage = @"Place page";
static NSString * const kStatPointToPoint = @"Point to point";
static NSString * const kStatPortrait = @"Portrait";
static NSString * const kStatProgress = @"Progress";
static NSString * const kStatPushReceived = @"Push received";
static NSString * const kStatRate = @"Rate";
static NSString * const kStatRegular = @"Regular";
static NSString * const kStatRemove = @"Remove";
static NSString * const kStatRename = @"Rename";
static NSString * const kStatReport = @"Report";
static NSString * const kStatScreen = @"Screen";
static NSString * const kStatSearch = @"Search";
static NSString * const kStatSearchEnteredState = @"Search entered state";
static NSString * const kStatSelectMap = @"Select map";
static NSString * const kStatSelectResult = @"Select result";
static NSString * const kStatSelectTab = @"Select tab";
static NSString * const kStatSendEmail = @"Send email";
static NSString * const kStatSettings = @"Settings";
static NSString * const kStatSettingsOpenSection = @"Settings open section";
static NSString * const kStatShare = @"Share";
static NSString * const kStatShowOnMap = @"Show on map";
static NSString * const kStatSocial = @"Social";
static NSString * const kStatSource = @"Source";
static NSString * const kStatStart = @"Start";
static NSString * const kStatSwapRoutingPoints = @"Swap routing points";
static NSString * const kStatTTS = @"TTS";
static NSString * const kStatTTSSettings = @"TTS settings";
static NSString * const kStatTable = @"Table";
static NSString * const kStatToMyPosition = @"To my position";
static NSString * const kStatToggleBookmark = @"Toggle bookmark";
static NSString * const kStatToggleCompassCalibration = @"Toggle compass calibration";
static NSString * const kStatToggleCoordinates = @"Toggle coordinates";
static NSString * const kStatToggleDownload = @"Toggle download";
static NSString * const kStatToggleSection = @"Toggle section";
static NSString * const kStatToggleStatistics = @"Toggle statistics";
static NSString * const kStatToggleVisibility = @"Toggle visibility";
static NSString * const kStatToggleZoomButtonsVisibility = @"Toggle zoom buttons visibility";
static NSString * const kStatUpdateAll = @"Update all";
static NSString * const kStatValue = @"Value";
static NSString * const kStatVehicle = @"Vehicle";
static NSString * const kStatVisible = @"Visible";
static NSString * const kStatWhatsNew = @"What's New";
static NSString * const kStatYes = @"Yes";
static NSString * const kStatZoom = @"Zoom";
static NSString * const kStatiPad = @"iPad";
static NSString * const kStatiPhone = @"iPhone";

static inline NSString * const kStatEventName(NSString * component, NSString * action)
{
  return [NSString stringWithFormat:@"%@ %@", component, action];
}
