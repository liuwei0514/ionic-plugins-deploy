var IonicDeploy = {
  check: function(app_id, domain, success, failure) {
    cordova.exec(
      success,
      failure,
      'IonicDeploy',
      'check',
      [app_id,domain]
    );
  },
  download: function(app_id, url, success, failure) {
  	cordova.exec(
  		success,
  		failure,
  		'IonicDeploy',
  		'download',
  		[app_id, url]
  	);
  },
  extract: function(app_id, success,failure) {
    cordova.exec(
      success,
      failure,
      'IonicDeploy',
      'extract',
      [app_id]
    );
  },
  redirect: function(app_id,domain, success, failure) {
  	cordova.exec(
  		success,
  		failure,
  		'IonicDeploy',
  		'redirect',
  		[app_id, domain]
  	);
  }
}

module.exports = IonicDeploy;
