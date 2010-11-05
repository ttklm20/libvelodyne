#ifndef VELODYNECALIBRATION_H
#define VELODYNECALIBRATION_H

#include "IOException.h"

#include <iosfwd>

#include <stdint.h>

class VelodynePointCloud;

class VelodyneCalibration {
  friend std::ostream& operator << (std::ostream &stream,
    const VelodyneCalibration &obj);
  friend std::istream& operator >> (std::istream &stream,
    VelodyneCalibration &obj);
  friend std::ofstream& operator << (std::ofstream &stream,
    const VelodyneCalibration &obj);
  friend std::ifstream& operator >> (std::ifstream &stream,
    VelodyneCalibration &obj) throw(IOException);

  friend class VelodynePointCloud;
  friend class VelodyneScanCloud;

  VelodyneCalibration(const VelodyneCalibration &other);
  VelodyneCalibration& operator = (const VelodyneCalibration &other);

  virtual void read(std::istream &stream);
  virtual void write(std::ostream &stream) const;
  virtual void read(std::ifstream &stream) throw(IOException);
  virtual void write(std::ofstream &stream) const;

  static const uint16_t mcu16LasersNbr = 64;

  struct VelodyneLaserCorrection {
    double mf64RotCorr;
    double mf64SinRotCorr;
    double mf64CosRotCorr;
    double mf64VertCorr;
    double mf64SinVertCorr;
    double mf64CosVertCorr;
    double mf64DistCorr;
    double mf64VertOffsCorr;
    double mf64HorizOffsCorr;
  };

  VelodyneLaserCorrection mCorr[mcu16LasersNbr];

  double deg2rad(double f64Deg) const;

public:
  VelodyneCalibration();
  ~VelodyneCalibration();

protected:

};

#endif // VELODYNECALIBRATION_H
