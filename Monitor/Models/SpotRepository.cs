using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Xml;
using System.Xml.Linq;

namespace SpotApp.Models
{
    public class SpotRepository : ISpotrRepository
    {
        public IEnumerable<Spot> GetAll()
        {
         


            var spots = new List<Spot>();
            var myFile = System.Web.Hosting.HostingEnvironment.MapPath("~");
            XDocument doc = XDocument.Load(myFile + "\\data\\ParkingStructure.xml");


            if (doc.Root != null)
            {
                var xElement = doc.Root;

                if (xElement != null)
                    foreach (XElement element in xElement.Elements())
                    {
                        Spot x = new Spot();
                        x.SpotId = (string)element.Attribute("ID");
                        x.SpotValue = (string)element.Attribute("Status");
                        spots.Add(x);

                    }
            }

           
            return spots.ToArray();
        }

        public Spot Get(string spotId)
        {
            Spot Spot = new Spot();
            string query = string.Format(" SELECT [SpotID], [CompanyName], [ContactName], [ContactTitle], [Address], [City], [Region], [PostalCode], [Country], [Phone], [Fax] FROM [Northwind].[dbo].[Spots] " +
                "  WHERE SpotID LIKE '%" + spotId + "%'");

            using (SqlConnection con =
                    new SqlConnection("your connection string"))
            {
                using (SqlCommand cmd = new SqlCommand(query, con))
                {
                    con.Open();
                    SqlDataReader reader = cmd.ExecuteReader();
                    
                    while (reader.Read())
                    {
                        //Spot.SpotID = reader.GetString(0);
                        //Spot.CompanyName = reader.GetString(1);
                        //Spot.ContactName = reader.GetString(2);
                        //Spot.ContactTitle = reader.GetString(3);
                        //Spot.Address = reader.GetString(4);
                        //Spot.City = reader.GetString(5);

                        //if (reader.GetValue(6) != null)
                        //{
                        //    Spot.Region = reader.GetValue(6).ToString();
                        //}
                        //else
                        //{
                        //    Spot.Region = string.Empty;
                        //}

                        //if (reader.GetValue(7) != null)
                        //{
                        //    Spot.PostalCode = reader.GetValue(7).ToString();
                        //}
                        //else
                        //{
                        //    Spot.PostalCode = string.Empty;
                        //}

                        //Spot.Country = reader.GetString(8);
                        //Spot.Phone = reader.GetString(9);

                        //if (reader.GetValue(10) != null)
                        //{
                        //    Spot.Fax = reader.GetValue(10).ToString();
                        //}
                        //else
                        //{
                        //    Spot.Fax = string.Empty;
                        //}
                        
                    }
                    con.Close(); 
                }
            }
            return Spot;
        }

        public Spot Add(Spot item)
        {
            string query = "";
            //string.Format("INSERT INTO [Northwind].[dbo].[Spots] " +
            //            " ( [SpotID], [CompanyName], [ContactName], [ContactTitle], [Address], [City], [Region], [PostalCode], [Country] " +
            //            " ,[Phone], [Fax] ) VALUES " +
            //           " ( '{0}', '{1}', '{2}', '{3}', '{4}',  '{5}', '{6}', '{7}', '{8}',  '{9}', '{10}' )", item.SpotID, item.CompanyName, item.ContactName,
            //           item.ContactTitle, item.Address, item.City, item.Region, item.PostalCode,  item.Country, item.Phone, item.Fax);

            using (SqlConnection con =
                    new SqlConnection("your connection string"))
            {
                using (SqlCommand cmd = new SqlCommand(query, con))
                {
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }

            return item;
        }

        public bool Remove(string spotId)
        {
            throw new NotImplementedException();
        }


        public bool Update(Spot item)
        {


            XmlDocument doc = new XmlDocument();
            var myFile = System.Web.Hosting.HostingEnvironment.MapPath("~");
            doc.Load(myFile + "\\data\\ParkingStructure.xml");



            // get a list of nodes - in this case, I'm selecting all <AID> nodes under
            // the <GroupAIDs> node - change to suit your needs



            XmlNodeList aNodes = doc.ChildNodes[0].ChildNodes;
            // loop through all AID nodes
            foreach (XmlNode aNode in aNodes)
            {
                // grab the "id" attribute
                XmlAttribute idAttribute = aNode.Attributes["ID"];
                XmlAttribute valAttribute = aNode.Attributes["Status"];
                // check if that attribute even exists...
                if (idAttribute != null)
                {
                    // if yes - read its current value
                    string currentValue = idAttribute.Value.Trim();
                    item.SpotId = item.SpotId.Trim();
                    // here, you can now decide what to do - for demo purposes,
                    // I just set the ID value to a fixed value if it was empty before
                    if (!string.IsNullOrEmpty(currentValue) && currentValue.Equals( item.SpotId))
                    {
                        if (valAttribute.Value == "1")
                            valAttribute.Value = "0";
                        else if (valAttribute.Value == "0")
                            valAttribute.Value = "1";
                    }
                }
            }

           



            // save the XmlDocument back to disk
            doc.Save(myFile + "\\data\\ParkingStructure.xml");

            return true;
        }
    }
}