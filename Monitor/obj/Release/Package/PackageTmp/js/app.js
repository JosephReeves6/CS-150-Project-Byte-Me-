 


(function () {

    var app = angular.module('newsFeed', []);

    app.controller('FeedController', ['$scope', 'FeedService', function ($scope, Feed) {

      //  console.log('FeedController called.');

        //These calls cause errors:
        //$scope.loadFeeds();
        //loadFeeds();
        //this.loadFeeds();
        //loadFeeds();
        $scope.rotoWorld = "";
        $scope.loadFeeds = function () {
           // console.log('loadFeeds called.');

            $scope.rotoWorld = Feed.parseFeed('api/spot/getall');
            
        };

    }]);

    app.factory('FeedService', ['$http', function($http) {
            return {
                parseFeed: function(url) {
                    var items = [];
                    $.getJSON("api/spot/getall", function(data) {

                        $.each(data, function(key, val) {
                            var spot = val;

                            items.push(spot);
                        });

                        return items;
                    });
                
                }
            }
        }
    ]);
})();

app.run(function ($http, MyService) {
    $http.get('api/spot/getall').success(function (data) {
        MyService.setData(data);
    });
});
myModule.service('MyService', function () {
    var myData = null;
    return {
        setData: function (data) {
            myData = data;
        },
        doStuff: function () {
            return myData.getSomeData();
        }
    };
})
//------------------------------------------------------
//(function () {

//    var app = angular.module('newsFeed', []);

//    app.controller('FeedController', ['$scope', 'FeedService', function ($scope, Feed) {

//        console.log($scope.rotoWorld);
//        console.log('6565656565656565656565656565');
//        //These calls cause errors:
//        //$scope.loadFeeds();
//        //loadFeeds();
//        //this.loadFeeds();
//        //loadFeeds();

//        $scope.rotoWorld = Feed.parseFeed(
//            "api/spot/getall"
//            );
//        $scope.loadFeeds = function () {
         
          

//            $scope.rotoWorld = Feed.parseFeed(
//                "api/spot/getall"
//                ) ;
//        };

//    }]);

//    app.factory('FeedService', ['$http', function ($http) {
//        return {
//            parseFeed: function (url) {
//                console.log('111111 called.');
//                $.getJSON("api/spot/getall", function (Data) {
//                    console.log('222222222 called.');

//                    return Data;

//                }).success(function (response) {
//                    console.log(response);
//                    return response;

//                });
//            }
//        };
//    }]);
//})();

 