// NOTE: If somone has used Firebase Storage or Cloudinary, then AWS S3 is like a burger with all the toppings. It provides a lot of features and flexibility, but it can be a bit more complex to set up and manage compared to simpler storage solutions. Just like a burger can have many toppings, AWS S3 offers various options for storage classes, access control, and integration with other AWS services. However, once you get the hang of it, it can be a powerful tool for storing and managing your data in the cloud.

import { S3Client } from "@aws-sdk/client-s3";
import { GetObjectCommand } from "@aws-sdk/client-s3";
import { getSignedUrl } from "@aws-sdk/s3-request-presigner";

const s3Client = new S3Client({
  region: "",
  credentials: {
    accessKeyId: "",
    secretAccessKey: "",
  },
});

const getObjectUrl = async (bucketName, objectKey) => {
  try {
    const command = new GetObjectCommand({
      Bucket: bucketName,
      Key: objectKey,
    });
    const url = await getSignedUrl(s3Client, command, { expiresIn: 3600 });
    return url;
  } catch (error) {
    console.error("Error generating signed URL:", error);
    throw error;
  }
};

getObjectUrl("dev-weekends-testing-bucket", "Copy of Fellowship 2026 branding kit.png")
  .then((url) => {
    console.log("Generated signed URL:", url);
  })
  .catch((error) => {
    console.error("Error:", error);
  });
