using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using SpotApp.Models;


namespace SpotApp.Controllers
{
    public class SpotController : ApiController
    {
        static readonly ISpotrRepository Repository = new SpotRepository();

        public IEnumerable<Spot> GetAllSpots()
        {
            return Repository.GetAll();
        }

        public Spot GetSpot(string spotId)
        {
            Spot spot = Repository.Get(spotId);
            if (spot == null)
            {
                throw new HttpResponseException(HttpStatusCode.NotFound);
            }
            return spot;
        }

        //public IEnumerable<Spot> GetSpotsByCountry(string country)
        //{
        //    return Repository.GetAll().Where(
        //        c => string.Equals(c.Country, country, StringComparison.OrdinalIgnoreCase));
        //}

        //public HttpResponseMessage PostSpot(Spot Spot)
        //{
        //    Spot = Repository.Add(Spot);
        //    var response = Request.CreateResponse<Spot>(HttpStatusCode.Created, Spot);

        //    string uri = Url.Link("DefaultApi", new { SpotID = Spot.SpotID });
        //    response.Headers.Location = new Uri(uri);
        //    return response;
        //}

        public void PutProduct(Spot Spot)
        {
           // Spot.SpotID = SpotID;
            if (!Repository.Update(Spot))
            {
                throw new HttpResponseException(HttpStatusCode.NotFound);
            }
        }

        public void DeleteProduct(string SpotID)
        {
            Spot Spot = Repository.Get(SpotID);
            if (Spot == null)
            {
                throw new HttpResponseException(HttpStatusCode.NotFound);
            }
            Repository.Remove(SpotID);
        }
    }
 
}