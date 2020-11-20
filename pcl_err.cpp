#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

void
  cloud_cb (const pcl::PCLPointCloud2::ConstPtr& cloud)
{
  if ((cloud->width * cloud->height) == 0)
    return;

  std::stringstream ss;
  ss << cloud->header.stamp << ".pcd";

  pcl::PCDWriter writer;
  writer.writeBinaryCompressed (ss.str (), *cloud, Eigen::Vector4f::Zero (),
              Eigen::Quaternionf::Identity ());

}

int main(int argc, char ** argv)
{
  pcl::PCLPointCloud2::Ptr cloud;
  cloud_cb(cloud);
  return 0;
}
