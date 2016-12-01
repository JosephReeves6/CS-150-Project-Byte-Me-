using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SpotApp.Models
{


    public interface ISpotrRepository
    {
        IEnumerable<Spot> GetAll();
        Spot Get(string spotId);
        Spot Add(Spot item);
        bool Remove(string spotId);
        bool Update(Spot item);
    }

}
