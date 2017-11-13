#include "httpd/fsdata.h"

static const unsigned char data_index_html[] = {
	/* /index.html */
	0x2F, 0x69, 0x6E, 0x64, 0x65, 0x78, 0x2E, 0x68, 0x74, 0x6D, 0x6C, 0,
	0x48, 0x54, 0x54, 0x50, 0x2F, 0x31, 0x2E, 0x30, 0x20, 0x32, 
	0x30, 0x30, 0x20, 0x4F, 0x4B, 0x0D, 0x0A, 0x6C, 0x77, 0x49, 
	0x50, 0x2F, 0x31, 0x2E, 0x34, 0x2E, 0x31, 0x20, 0x28, 0x68, 
	0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x73, 0x61, 0x76, 0x61, 
	0x6E, 0x6E, 0x61, 0x68, 0x2E, 0x6E, 0x6F, 0x6E, 0x67, 0x6E, 
	0x75, 0x2E, 0x6F, 0x72, 0x67, 0x2F, 0x70, 0x72, 0x6F, 0x6A, 
	0x65, 0x63, 0x74, 0x73, 0x2F, 0x6C, 0x77, 0x69, 0x70, 0x29, 
	0x0D, 0x0A, 0x43, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 
	0x74, 0x79, 0x70, 0x65, 0x3A, 0x20, 0x74, 0x65, 0x78, 0x74, 
	0x2F, 0x68, 0x74, 0x6D, 0x6C, 0x0D, 0x0A, 0x0D, 0x0A, 0x3C, 
	0x21, 0x44, 0x4F, 0x43, 0x54, 0x59, 0x50, 0x45, 0x20, 0x68, 
	0x74, 0x6D, 0x6C, 0x3E, 0x0A, 0x3C, 0x68, 0x74, 0x6D, 0x6C, 
	0x3E, 0x0A, 0x09, 0x3C, 0x68, 0x65, 0x61, 0x64, 0x3E, 0x0A, 
	0x09, 0x09, 0x3C, 0x6D, 0x65, 0x74, 0x61, 0x20, 0x63, 0x68, 
	0x61, 0x72, 0x73, 0x65, 0x74, 0x3D, 0x22, 0x75, 0x74, 0x66, 
	0x2D, 0x38, 0x22, 0x3E, 0x0A, 0x09, 0x09, 0x3C, 0x6D, 0x65, 
	0x74, 0x61, 0x20, 0x6E, 0x61, 0x6D, 0x65, 0x3D, 0x22, 0x76, 
	0x69, 0x65, 0x77, 0x70, 0x6F, 0x72, 0x74, 0x22, 0x20, 0x63, 
	0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x3D, 0x22, 0x77, 0x69, 
	0x64, 0x74, 0x68, 0x3D, 0x64, 0x65, 0x76, 0x69, 0x63, 0x65, 
	0x2D, 0x77, 0x69, 0x64, 0x74, 0x68, 0x2C, 0x20, 0x75, 0x73, 
	0x65, 0x72, 0x2D, 0x73, 0x63, 0x61, 0x6C, 0x61, 0x62, 0x6C, 
	0x65, 0x3D, 0x6E, 0x6F, 0x22, 0x3E, 0x0A, 0x09, 0x09, 0x3C, 
	0x6C, 0x69, 0x6E, 0x6B, 0x20, 0x72, 0x65, 0x6C, 0x3D, 0x22, 
	0x73, 0x68, 0x6F, 0x72, 0x74, 0x63, 0x75, 0x74, 0x20, 0x69, 
	0x63, 0x6F, 0x6E, 0x22, 0x20, 0x68, 0x72, 0x65, 0x66, 0x3D, 
	0x22, 0x69, 0x6D, 0x67, 0x2F, 0x66, 0x61, 0x76, 0x69, 0x63, 
	0x6F, 0x6E, 0x2E, 0x70, 0x6E, 0x67, 0x22, 0x3E, 0x0A, 0x09, 
	0x09, 0x3C, 0x74, 0x69, 0x74, 0x6C, 0x65, 0x3E, 0x57, 0x65, 
	0x62, 0x53, 0x6F, 0x63, 0x6B, 0x65, 0x74, 0x20, 0x44, 0x65, 
	0x6D, 0x6F, 0x3C, 0x2F, 0x74, 0x69, 0x74, 0x6C, 0x65, 0x3E, 
	0x0A, 0x09, 0x3C, 0x2F, 0x68, 0x65, 0x61, 0x64, 0x3E, 0x0A, 
	0x09, 0x3C, 0x62, 0x6F, 0x64, 0x79, 0x3E, 0x0A, 0x09, 0x09, 
	0x3C, 0x68, 0x31, 0x3E, 0x57, 0x65, 0x62, 0x53, 0x6F, 0x63, 
	0x6B, 0x65, 0x74, 0x20, 0x44, 0x65, 0x6D, 0x6F, 0x3C, 0x2F, 
	0x68, 0x31, 0x3E, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x3C, 0x62, 
	0x3E, 0x57, 0x53, 0x20, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 
	0x3A, 0x20, 0x3C, 0x70, 0x20, 0x69, 0x64, 0x3D, 0x22, 0x73, 
	0x74, 0x61, 0x74, 0x75, 0x73, 0x22, 0x20, 0x73, 0x74, 0x79, 
	0x6C, 0x65, 0x3D, 0x22, 0x64, 0x69, 0x73, 0x70, 0x6C, 0x61, 
	0x79, 0x3A, 0x20, 0x69, 0x6E, 0x6C, 0x69, 0x6E, 0x65, 0x2D, 
	0x62, 0x6C, 0x6F, 0x63, 0x6B, 0x3B, 0x22, 0x3E, 0x4F, 0x66, 
	0x66, 0x6C, 0x69, 0x6E, 0x65, 0x3C, 0x2F, 0x70, 0x3E, 0x3C, 
	0x2F, 0x62, 0x3E, 0x0A, 0x09, 0x09, 0x3C, 0x64, 0x69, 0x76, 
	0x20, 0x73, 0x74, 0x79, 0x6C, 0x65, 0x3D, 0x22, 0x70, 0x61, 
	0x64, 0x64, 0x69, 0x6E, 0x67, 0x2D, 0x62, 0x6F, 0x74, 0x74, 
	0x6F, 0x6D, 0x3A, 0x20, 0x31, 0x65, 0x6D, 0x3B, 0x22, 0x3E, 
	0x0A, 0x09, 0x09, 0x09, 0x3C, 0x62, 0x75, 0x74, 0x74, 0x6F, 
	0x6E, 0x20, 0x69, 0x64, 0x3D, 0x22, 0x70, 0x69, 0x6E, 0x67, 
	0x2D, 0x62, 0x74, 0x6E, 0x22, 0x20, 0x6F, 0x6E, 0x63, 0x6C, 
	0x69, 0x63, 0x6B, 0x3D, 0x22, 0x77, 0x73, 0x57, 0x72, 0x69, 
	0x74, 0x65, 0x28, 0x27, 0x70, 0x69, 0x6E, 0x67, 0x27, 0x29, 
	0x3B, 0x22, 0x20, 0x64, 0x69, 0x73, 0x61, 0x62, 0x6C, 0x65, 
	0x64, 0x3E, 0x53, 0x65, 0x6E, 0x64, 0x20, 0x50, 0x69, 0x6E, 
	0x67, 0x3C, 0x2F, 0x62, 0x75, 0x74, 0x74, 0x6F, 0x6E, 0x3E, 
	0x0A, 0x09, 0x09, 0x09, 0x3C, 0x62, 0x75, 0x74, 0x74, 0x6F, 
	0x6E, 0x20, 0x69, 0x64, 0x3D, 0x22, 0x62, 0x63, 0x61, 0x73, 
	0x74, 0x2D, 0x62, 0x74, 0x6E, 0x22, 0x20, 0x6F, 0x6E, 0x63, 
	0x6C, 0x69, 0x63, 0x6B, 0x3D, 0x22, 0x77, 0x73, 0x57, 0x72, 
	0x69, 0x74, 0x65, 0x28, 0x27, 0x62, 0x63, 0x61, 0x73, 0x74, 
	0x27, 0x29, 0x3B, 0x22, 0x20, 0x64, 0x69, 0x73, 0x61, 0x62, 
	0x6C, 0x65, 0x64, 0x3E, 0x53, 0x65, 0x6E, 0x64, 0x20, 0x42, 
	0x72, 0x6F, 0x61, 0x64, 0x63, 0x61, 0x73, 0x74, 0x3C, 0x2F, 
	0x62, 0x75, 0x74, 0x74, 0x6F, 0x6E, 0x3E, 0x0A, 0x09, 0x09, 
	0x3C, 0x2F, 0x64, 0x69, 0x76, 0x3E, 0x0A, 0x09, 0x09, 0x3C, 
	0x74, 0x65, 0x78, 0x74, 0x61, 0x72, 0x65, 0x61, 0x20, 0x69, 
	0x64, 0x3D, 0x22, 0x6F, 0x75, 0x74, 0x70, 0x75, 0x74, 0x22, 
	0x20, 0x73, 0x74, 0x79, 0x6C, 0x65, 0x3D, 0x22, 0x77, 0x69, 
	0x64, 0x74, 0x68, 0x3A, 0x20, 0x32, 0x30, 0x65, 0x6D, 0x3B, 
	0x20, 0x68, 0x65, 0x69, 0x67, 0x68, 0x74, 0x3A, 0x20, 0x31, 
	0x35, 0x65, 0x6D, 0x3B, 0x22, 0x20, 0x72, 0x65, 0x61, 0x64, 
	0x6F, 0x6E, 0x6C, 0x79, 0x3E, 0x3C, 0x2F, 0x74, 0x65, 0x78, 
	0x74, 0x61, 0x72, 0x65, 0x61, 0x3E, 0x0A, 0x09, 0x09, 0x3C, 
	0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x3E, 0x0A, 0x09, 0x09, 
	0x76, 0x61, 0x72, 0x20, 0x77, 0x73, 0x3B, 0x0A, 0x09, 0x09, 
	0x76, 0x61, 0x72, 0x20, 0x72, 0x65, 0x74, 0x72, 0x69, 0x65, 
	0x73, 0x20, 0x3D, 0x20, 0x30, 0x3B, 0x0A, 0x0A, 0x09, 0x09, 
	0x77, 0x69, 0x6E, 0x64, 0x6F, 0x77, 0x2E, 0x6F, 0x6E, 0x6C, 
	0x6F, 0x61, 0x64, 0x20, 0x3D, 0x20, 0x66, 0x75, 0x6E, 0x63, 
	0x74, 0x69, 0x6F, 0x6E, 0x28, 0x29, 0x20, 0x7B, 0x0A, 0x09, 
	0x09, 0x09, 0x77, 0x73, 0x4F, 0x70, 0x65, 0x6E, 0x28, 0x29, 
	0x3B, 0x0A, 0x09, 0x09, 0x7D, 0x0A, 0x0A, 0x09, 0x09, 0x66, 
	0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x73, 0x65, 
	0x74, 0x42, 0x75, 0x74, 0x74, 0x6F, 0x6E, 0x53, 0x74, 0x61, 
	0x74, 0x65, 0x28, 0x73, 0x74, 0x61, 0x74, 0x65, 0x29, 0x20, 
	0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x64, 0x6F, 0x63, 0x75, 
	0x6D, 0x65, 0x6E, 0x74, 0x2E, 0x67, 0x65, 0x74, 0x45, 0x6C, 
	0x65, 0x6D, 0x65, 0x6E, 0x74, 0x42, 0x79, 0x49, 0x64, 0x28, 
	0x27, 0x70, 0x69, 0x6E, 0x67, 0x2D, 0x62, 0x74, 0x6E, 0x27, 
	0x29, 0x2E, 0x64, 0x69, 0x73, 0x61, 0x62, 0x6C, 0x65, 0x64, 
	0x20, 0x3D, 0x20, 0x73, 0x74, 0x61, 0x74, 0x65, 0x3B, 0x0A, 
	0x09, 0x09, 0x09, 0x09, 0x64, 0x6F, 0x63, 0x75, 0x6D, 0x65, 
	0x6E, 0x74, 0x2E, 0x67, 0x65, 0x74, 0x45, 0x6C, 0x65, 0x6D, 
	0x65, 0x6E, 0x74, 0x42, 0x79, 0x49, 0x64, 0x28, 0x27, 0x62, 
	0x63, 0x61, 0x73, 0x74, 0x2D, 0x62, 0x74, 0x6E, 0x27, 0x29, 
	0x2E, 0x64, 0x69, 0x73, 0x61, 0x62, 0x6C, 0x65, 0x64, 0x20, 
	0x3D, 0x20, 0x73, 0x74, 0x61, 0x74, 0x65, 0x3B, 0x0A, 0x09, 
	0x09, 0x7D, 0x0A, 0x0A, 0x09, 0x09, 0x66, 0x75, 0x6E, 0x63, 
	0x74, 0x69, 0x6F, 0x6E, 0x20, 0x73, 0x65, 0x74, 0x53, 0x74, 
	0x61, 0x74, 0x75, 0x73, 0x28, 0x6D, 0x73, 0x67, 0x29, 0x20, 
	0x7B, 0x0A, 0x09, 0x09, 0x09, 0x64, 0x6F, 0x63, 0x75, 0x6D, 
	0x65, 0x6E, 0x74, 0x2E, 0x67, 0x65, 0x74, 0x45, 0x6C, 0x65, 
	0x6D, 0x65, 0x6E, 0x74, 0x42, 0x79, 0x49, 0x64, 0x28, 0x27, 
	0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x27, 0x29, 0x2E, 0x69, 
	0x6E, 0x6E, 0x65, 0x72, 0x48, 0x54, 0x4D, 0x4C, 0x20, 0x3D, 
	0x20, 0x6D, 0x73, 0x67, 0x3B, 0x0A, 0x09, 0x09, 0x7D, 0x0A, 
	0x0A, 0x09, 0x09, 0x66, 0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 
	0x6E, 0x20, 0x77, 0x73, 0x4F, 0x70, 0x65, 0x6E, 0x28, 0x29, 
	0x20, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x69, 0x66, 0x20, 0x28, 
	0x77, 0x73, 0x20, 0x3D, 0x3D, 0x3D, 0x20, 0x75, 0x6E, 0x64, 
	0x65, 0x66, 0x69, 0x6E, 0x65, 0x64, 0x20, 0x7C, 0x7C, 0x20, 
	0x77, 0x73, 0x2E, 0x72, 0x65, 0x61, 0x64, 0x79, 0x53, 0x74, 
	0x61, 0x74, 0x65, 0x20, 0x21, 0x3D, 0x20, 0x30, 0x29, 0x20, 
	0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x69, 0x66, 0x20, 0x28, 
	0x72, 0x65, 0x74, 0x72, 0x69, 0x65, 0x73, 0x29, 0x0A, 0x09, 
	0x09, 0x09, 0x09, 0x09, 0x73, 0x65, 0x74, 0x53, 0x74, 0x61, 
	0x74, 0x75, 0x73, 0x28, 0x22, 0x57, 0x65, 0x62, 0x53, 0x6F, 
	0x63, 0x6B, 0x65, 0x74, 0x20, 0x74, 0x69, 0x6D, 0x65, 0x6F, 
	0x75, 0x74, 0x2C, 0x20, 0x72, 0x65, 0x74, 0x72, 0x79, 0x69, 
	0x6E, 0x67, 0x2E, 0x2E, 0x22, 0x29, 0x3B, 0x0A, 0x09, 0x09, 
	0x09, 0x09, 0x65, 0x6C, 0x73, 0x65, 0x0A, 0x09, 0x09, 0x09, 
	0x09, 0x09, 0x73, 0x65, 0x74, 0x53, 0x74, 0x61, 0x74, 0x75, 
	0x73, 0x28, 0x22, 0x4F, 0x70, 0x65, 0x6E, 0x69, 0x6E, 0x67, 
	0x20, 0x57, 0x65, 0x62, 0x53, 0x6F, 0x63, 0x6B, 0x65, 0x74, 
	0x2E, 0x2E, 0x22, 0x29, 0x3B, 0x0A, 0x0A, 0x09, 0x09, 0x09, 
	0x09, 0x77, 0x73, 0x20, 0x3D, 0x20, 0x6E, 0x65, 0x77, 0x20, 
	0x57, 0x65, 0x62, 0x53, 0x6F, 0x63, 0x6B, 0x65, 0x74, 0x28, 
	0x22, 0x77, 0x73, 0x3A, 0x2F, 0x2F, 0x22, 0x20, 0x2B, 0x20, 
	0x6C, 0x6F, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x2E, 0x68, 
	0x6F, 0x73, 0x74, 0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x09, 
	0x77, 0x73, 0x2E, 0x62, 0x69, 0x6E, 0x61, 0x72, 0x79, 0x54, 
	0x79, 0x70, 0x65, 0x20, 0x3D, 0x20, 0x27, 0x61, 0x72, 0x72, 
	0x61, 0x79, 0x62, 0x75, 0x66, 0x66, 0x65, 0x72, 0x27, 0x3B, 
	0x0A, 0x09, 0x09, 0x09, 0x09, 0x77, 0x73, 0x2E, 0x6F, 0x6E, 
	0x6F, 0x70, 0x65, 0x6E, 0x20, 0x3D, 0x20, 0x66, 0x75, 0x6E, 
	0x63, 0x74, 0x69, 0x6F, 0x6E, 0x28, 0x65, 0x76, 0x74, 0x29, 
	0x20, 0x7B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x72, 0x65, 
	0x74, 0x72, 0x69, 0x65, 0x73, 0x20, 0x3D, 0x20, 0x30, 0x3B, 
	0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x73, 0x65, 0x74, 0x53, 
	0x74, 0x61, 0x74, 0x75, 0x73, 0x28, 0x22, 0x57, 0x65, 0x62, 
	0x53, 0x6F, 0x63, 0x6B, 0x65, 0x74, 0x20, 0x69, 0x73, 0x20, 
	0x6F, 0x70, 0x65, 0x6E, 0x2E, 0x22, 0x29, 0x3B, 0x0A, 0x09, 
	0x09, 0x09, 0x09, 0x09, 0x73, 0x65, 0x74, 0x42, 0x75, 0x74, 
	0x74, 0x6F, 0x6E, 0x53, 0x74, 0x61, 0x74, 0x65, 0x28, 0x66, 
	0x61, 0x6C, 0x73, 0x65, 0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 
	0x09, 0x7D, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x77, 0x73, 
	0x2E, 0x6F, 0x6E, 0x65, 0x72, 0x72, 0x6F, 0x72, 0x20, 0x3D, 
	0x20, 0x66, 0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x28, 
	0x65, 0x76, 0x74, 0x29, 0x20, 0x7B, 0x0A, 0x09, 0x09, 0x09, 
	0x09, 0x09, 0x73, 0x65, 0x74, 0x53, 0x74, 0x61, 0x74, 0x75, 
	0x73, 0x28, 0x22, 0x57, 0x65, 0x62, 0x53, 0x6F, 0x63, 0x6B, 
	0x65, 0x74, 0x20, 0x65, 0x72, 0x72, 0x6F, 0x72, 0x21, 0x22, 
	0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x73, 0x65, 
	0x74, 0x42, 0x75, 0x74, 0x74, 0x6F, 0x6E, 0x53, 0x74, 0x61, 
	0x74, 0x65, 0x28, 0x74, 0x72, 0x75, 0x65, 0x29, 0x3B, 0x0A, 
	0x09, 0x09, 0x09, 0x09, 0x7D, 0x3B, 0x0A, 0x09, 0x09, 0x09, 
	0x09, 0x77, 0x73, 0x2E, 0x6F, 0x6E, 0x6D, 0x65, 0x73, 0x73, 
	0x61, 0x67, 0x65, 0x20, 0x3D, 0x20, 0x66, 0x75, 0x6E, 0x63, 
	0x74, 0x69, 0x6F, 0x6E, 0x28, 0x65, 0x76, 0x74, 0x29, 0x20, 
	0x7B, 0x20, 0x6F, 0x6E, 0x4D, 0x65, 0x73, 0x73, 0x61, 0x67, 
	0x65, 0x28, 0x65, 0x76, 0x74, 0x29, 0x3B, 0x20, 0x7D, 0x3B, 
	0x0A, 0x09, 0x09, 0x09, 0x7D, 0x0A, 0x09, 0x09, 0x7D, 0x0A, 
	0x0A, 0x09, 0x09, 0x66, 0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 
	0x6E, 0x20, 0x77, 0x73, 0x57, 0x72, 0x69, 0x74, 0x65, 0x28, 
	0x64, 0x61, 0x74, 0x61, 0x29, 0x20, 0x7B, 0x0A, 0x09, 0x09, 
	0x09, 0x69, 0x66, 0x20, 0x28, 0x77, 0x73, 0x2E, 0x72, 0x65, 
	0x61, 0x64, 0x79, 0x53, 0x74, 0x61, 0x74, 0x65, 0x20, 0x3D, 
	0x3D, 0x20, 0x33, 0x20, 0x7C, 0x7C, 0x20, 0x72, 0x65, 0x74, 
	0x72, 0x69, 0x65, 0x73, 0x2B, 0x2B, 0x20, 0x3E, 0x20, 0x32, 
	0x29, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x77, 0x73, 0x4F, 0x70, 
	0x65, 0x6E, 0x28, 0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x65, 
	0x6C, 0x73, 0x65, 0x20, 0x69, 0x66, 0x20, 0x28, 0x77, 0x73, 
	0x2E, 0x72, 0x65, 0x61, 0x64, 0x79, 0x53, 0x74, 0x61, 0x74, 
	0x65, 0x20, 0x3D, 0x3D, 0x20, 0x31, 0x29, 0x0A, 0x09, 0x09, 
	0x09, 0x09, 0x77, 0x73, 0x2E, 0x73, 0x65, 0x6E, 0x64, 0x28, 
	0x64, 0x61, 0x74, 0x61, 0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 
	0x09, 0x72, 0x65, 0x74, 0x72, 0x69, 0x65, 0x73, 0x20, 0x3D, 
	0x20, 0x30, 0x3B, 0x0A, 0x09, 0x09, 0x7D, 0x0A, 0x0A, 0x09, 
	0x09, 0x66, 0x75, 0x6E, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x20, 
	0x6F, 0x6E, 0x4D, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x28, 
	0x65, 0x76, 0x74, 0x29, 0x20, 0x7B, 0x0A, 0x09, 0x09, 0x09, 
	0x63, 0x6F, 0x6E, 0x73, 0x6F, 0x6C, 0x65, 0x2E, 0x6C, 0x6F, 
	0x67, 0x28, 0x65, 0x76, 0x74, 0x2E, 0x64, 0x61, 0x74, 0x61, 
	0x29, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x64, 0x6F, 0x63, 0x75, 
	0x6D, 0x65, 0x6E, 0x74, 0x2E, 0x67, 0x65, 0x74, 0x45, 0x6C, 
	0x65, 0x6D, 0x65, 0x6E, 0x74, 0x42, 0x79, 0x49, 0x64, 0x28, 
	0x27, 0x6F, 0x75, 0x74, 0x70, 0x75, 0x74, 0x27, 0x29, 0x2E, 
	0x69, 0x6E, 0x6E, 0x65, 0x72, 0x48, 0x54, 0x4D, 0x4C, 0x20, 
	0x2B, 0x3D, 0x20, 0x65, 0x76, 0x74, 0x2E, 0x64, 0x61, 0x74, 
	0x61, 0x3B, 0x0A, 0x09, 0x09, 0x09, 0x64, 0x6F, 0x63, 0x75, 
	0x6D, 0x65, 0x6E, 0x74, 0x2E, 0x67, 0x65, 0x74, 0x45, 0x6C, 
	0x65, 0x6D, 0x65, 0x6E, 0x74, 0x42, 0x79, 0x49, 0x64, 0x28, 
	0x27, 0x6F, 0x75, 0x74, 0x70, 0x75, 0x74, 0x27, 0x29, 0x2E, 
	0x69, 0x6E, 0x6E, 0x65, 0x72, 0x48, 0x54, 0x4D, 0x4C, 0x20, 
	0x2B, 0x3D, 0x20, 0x22, 0x5C, 0x6E, 0x22, 0x3B, 0x0A, 0x09, 
	0x09, 0x09, 0x2F, 0x2F, 0x20, 0x76, 0x61, 0x72, 0x20, 0x73, 
	0x74, 0x61, 0x74, 0x73, 0x20, 0x3D, 0x20, 0x4A, 0x53, 0x4F, 
	0x4E, 0x2E, 0x70, 0x61, 0x72, 0x73, 0x65, 0x28, 0x65, 0x76, 
	0x74, 0x2E, 0x64, 0x61, 0x74, 0x61, 0x29, 0x3B, 0x0A, 0x09, 
	0x09, 0x09, 0x2F, 0x2F, 0x20, 0x63, 0x6F, 0x6E, 0x73, 0x6F, 
	0x6C, 0x65, 0x2E, 0x6C, 0x6F, 0x67, 0x28, 0x73, 0x74, 0x61, 
	0x74, 0x73, 0x29, 0x3B, 0x0A, 0x09, 0x09, 0x7D, 0x0A, 0x0A, 
	0x09, 0x09, 0x3C, 0x2F, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 
	0x3E, 0x0A, 0x09, 0x3C, 0x2F, 0x62, 0x6F, 0x64, 0x79, 0x3E, 
	0x0A, 0x3C, 0x2F, 0x68, 0x74, 0x6D, 0x6C, 0x3E, 0x0A, };

static const unsigned char data_img_favicon_png[] = {
	/* /img/favicon.png */
	0x2F, 0x69, 0x6D, 0x67, 0x2F, 0x66, 0x61, 0x76, 0x69, 0x63, 0x6F, 0x6E, 0x2E, 0x70, 0x6E, 0x67, 0,
	0x48, 0x54, 0x54, 0x50, 0x2F, 0x31, 0x2E, 0x30, 0x20, 0x32, 
	0x30, 0x30, 0x20, 0x4F, 0x4B, 0x0D, 0x0A, 0x6C, 0x77, 0x49, 
	0x50, 0x2F, 0x31, 0x2E, 0x34, 0x2E, 0x31, 0x20, 0x28, 0x68, 
	0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x73, 0x61, 0x76, 0x61, 
	0x6E, 0x6E, 0x61, 0x68, 0x2E, 0x6E, 0x6F, 0x6E, 0x67, 0x6E, 
	0x75, 0x2E, 0x6F, 0x72, 0x67, 0x2F, 0x70, 0x72, 0x6F, 0x6A, 
	0x65, 0x63, 0x74, 0x73, 0x2F, 0x6C, 0x77, 0x69, 0x70, 0x29, 
	0x0D, 0x0A, 0x43, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 
	0x74, 0x79, 0x70, 0x65, 0x3A, 0x20, 0x69, 0x6D, 0x61, 0x67, 
	0x65, 0x2F, 0x70, 0x6E, 0x67, 0x0D, 0x0A, 0x0D, 0x0A, 0x89, 
	0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 
	0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x10, 0x00, 
	0x00, 0x00, 0x10, 0x08, 0x06, 0x00, 0x00, 0x00, 0x1F, 0xF3, 
	0xFF, 0x61, 0x00, 0x00, 0x02, 0xBF, 0x49, 0x44, 0x41, 0x54, 
	0x38, 0xCB, 0xA5, 0x92, 0x4F, 0x6C, 0x14, 0x75, 0x14, 0xC7, 
	0x3F, 0x3B, 0x3B, 0x33, 0xFB, 0xBF, 0xBB, 0x74, 0x59, 0xD8, 
	0xA5, 0xC5, 0x76, 0x4B, 0x65, 0x6B, 0x49, 0x10, 0x41, 0x41, 
	0x20, 0x84, 0xD2, 0x80, 0x6D, 0x6C, 0x62, 0x80, 0xC4, 0x78, 
	0xF1, 0x64, 0xD2, 0x93, 0x89, 0x77, 0xF1, 0xE4, 0xD9, 0x83, 
	0x37, 0x63, 0x3C, 0xE0, 0xC5, 0x43, 0x2F, 0x46, 0x23, 0x90, 
	0x70, 0x30, 0x01, 0xA5, 0x6A, 0x29, 0x2D, 0x65, 0xA1, 0x14, 
	0xD3, 0xAD, 0x08, 0xBB, 0x9A, 0xD9, 0xA6, 0xBB, 0x65, 0xF6, 
	0x5F, 0x67, 0x77, 0xE7, 0x37, 0xF3, 0xF3, 0x62, 0xD7, 0xA6, 
	0xE2, 0xC9, 0x77, 0x79, 0x2F, 0x2F, 0xEF, 0xFB, 0xC9, 0x37, 
	0x2F, 0x5F, 0xF8, 0x9F, 0xE5, 0xD9, 0xBE, 0x78, 0x77, 0xF2, 
	0x83, 0x54, 0xA2, 0x7F, 0xF8, 0x13, 0xAF, 0x2F, 0xFC, 0xB6, 
	0xAB, 0x06, 0xF4, 0xEE, 0xB0, 0x9F, 0xDB, 0xF3, 0xD9, 0x92, 
	0x91, 0x5F, 0xF9, 0x72, 0xEE, 0xDA, 0xE5, 0x4B, 0x80, 0xF8, 
	0x4F, 0xC0, 0x89, 0x8B, 0xEF, 0xBF, 0x63, 0x05, 0x52, 0x53, 
	0x17, 0x26, 0xC6, 0x19, 0x39, 0xD4, 0x47, 0xD0, 0xA7, 0x52, 
	0xB1, 0xDA, 0x2C, 0x3D, 0x2D, 0xF3, 0xFD, 0x4F, 0x77, 0x29, 
	0xAE, 0x64, 0x6D, 0xBF, 0x65, 0xBC, 0xF2, 0xC3, 0x95, 0xAF, 
	0x1E, 0x6E, 0x6A, 0x94, 0x8E, 0x7A, 0xE7, 0xD1, 0xB1, 0xAA, 
	0x9E, 0x9A, 0x7A, 0x61, 0xE8, 0x30, 0xAA, 0x3F, 0x84, 0x5F, 
	0x53, 0xD8, 0xB7, 0x3B, 0x44, 0x40, 0xF3, 0x52, 0x6D, 0x41, 
	0xAA, 0xA7, 0x8F, 0x57, 0x8F, 0x9F, 0xD6, 0x0E, 0x1D, 0x3B, 
	0xB5, 0x08, 0xEC, 0xD9, 0x94, 0x79, 0x37, 0x07, 0x2D, 0x73, 
	0x26, 0x77, 0x76, 0x74, 0xD4, 0xB3, 0x27, 0xB9, 0x8B, 0xC1, 
	0x54, 0x17, 0x89, 0xA8, 0x1F, 0xAB, 0xED, 0x10, 0xF6, 0xAB, 
	0xEC, 0x8D, 0x07, 0xD1, 0x75, 0x8D, 0x74, 0x32, 0x8A, 0xA2, 
	0xFA, 0x88, 0xEC, 0xDA, 0x7B, 0xEE, 0xD1, 0xDC, 0x8F, 0x9F, 
	0x77, 0x1C, 0x4C, 0xBC, 0xF7, 0xE1, 0xE4, 0x81, 0xE1, 0x03, 
	0x9E, 0xA6, 0x03, 0x45, 0xB3, 0xC9, 0xFE, 0x54, 0x84, 0xB6, 
	0x70, 0x51, 0x14, 0x0F, 0xEB, 0xF5, 0x36, 0x56, 0x5B, 0xD0, 
	0xDB, 0x1D, 0xC4, 0xA7, 0xAB, 0x44, 0x23, 0x61, 0x32, 0x99, 
	0xCC, 0x41, 0xD8, 0x99, 0xE9, 0x00, 0xA2, 0xB1, 0xEE, 0xB1, 
	0x42, 0xA9, 0x8E, 0xEB, 0xBA, 0x9C, 0x3F, 0xDA, 0x83, 0x69, 
	0xD9, 0xE4, 0x8C, 0x1A, 0xCB, 0x46, 0x8D, 0xAA, 0x65, 0x53, 
	0x6B, 0x0A, 0x5A, 0xB6, 0x4D, 0x2C, 0xA4, 0x23, 0x5C, 0x49, 
	0x38, 0x12, 0x63, 0x68, 0x64, 0x74, 0xBC, 0x03, 0x10, 0xAE, 
	0x4C, 0xB9, 0xAE, 0x64, 0xF4, 0xE5, 0x5E, 0xBA, 0x02, 0x2A, 
	0xAE, 0x10, 0x44, 0x83, 0x1A, 0xB3, 0x2B, 0xEB, 0xAC, 0x18, 
	0x35, 0xCC, 0x5A, 0x93, 0xC7, 0x46, 0x85, 0xB6, 0xED, 0x20, 
	0xA5, 0x8B, 0x70, 0x1C, 0xF6, 0xA7, 0xFB, 0x77, 0x77, 0x00, 
	0xD9, 0xA5, 0x5C, 0xA9, 0x65, 0x35, 0x28, 0x99, 0x75, 0x2A, 
	0xB5, 0x06, 0x21, 0x5D, 0xC1, 0x15, 0x36, 0xC7, 0x06, 0xBA, 
	0xF0, 0x79, 0x5D, 0x14, 0x1C, 0xE2, 0x61, 0x15, 0x29, 0x1D, 
	0x14, 0x24, 0x9A, 0xD7, 0xC3, 0xAD, 0x3B, 0xD9, 0xF5, 0xCE, 
	0x13, 0xCB, 0x76, 0x24, 0xB9, 0x6F, 0xA0, 0x6F, 0xBC, 0x58, 
	0xB5, 0x69, 0xD8, 0x92, 0x54, 0x3C, 0x4C, 0xAB, 0x2D, 0x10, 
	0xC2, 0xE1, 0x59, 0x75, 0x03, 0x9F, 0xEA, 0x21, 0xF7, 0x47, 
	0x09, 0x5C, 0x87, 0x46, 0xA3, 0x4E, 0x76, 0x71, 0x89, 0xD9, 
	0x6F, 0xAF, 0x5E, 0x82, 0x8A, 0xA1, 0x02, 0xD0, 0x58, 0xFB, 
	0xAC, 0x55, 0x2B, 0x7F, 0x3A, 0x3D, 0x6B, 0xA2, 0xA9, 0x5E, 
	0xCE, 0x1E, 0xEE, 0x47, 0x91, 0x12, 0xC7, 0x71, 0x09, 0xEA, 
	0x1E, 0x96, 0xF3, 0xAB, 0xDC, 0x5B, 0xFE, 0x93, 0x2B, 0x86, 
	0x01, 0x96, 0x89, 0x59, 0xFC, 0xBD, 0x00, 0xF9, 0xF9, 0x7F, 
	0x72, 0x50, 0x5E, 0x6A, 0x0F, 0xF7, 0x27, 0x26, 0x69, 0x94, 
	0xA8, 0x9B, 0x25, 0x56, 0xD7, 0xCA, 0x94, 0xD6, 0x4D, 0x76, 
	0x84, 0x34, 0x16, 0x73, 0x79, 0xA6, 0xAE, 0xCF, 0x50, 0x28, 
	0x14, 0x58, 0x98, 0xBF, 0xC7, 0x6F, 0xB9, 0x5F, 0xF1, 0x79, 
	0xDD, 0x37, 0xFF, 0x95, 0x83, 0xDC, 0xC2, 0xF4, 0xDD, 0x93, 
	0x23, 0xE7, 0x64, 0x2C, 0xA4, 0x9F, 0x39, 0xF2, 0x52, 0x1A, 
	0x21, 0x04, 0x5F, 0x7C, 0x7D, 0x93, 0xEF, 0x6E, 0xCC, 0xB1, 
	0x56, 0x28, 0xF0, 0xC6, 0xEB, 0x83, 0x2C, 0x3E, 0xB8, 0x4F, 
	0x44, 0x97, 0xE3, 0xF9, 0x99, 0x6F, 0x7E, 0x79, 0x5E, 0x94, 
	0x35, 0x20, 0x46, 0xA0, 0xE7, 0xAD, 0x17, 0x5F, 0x3B, 0xF5, 
	0x91, 0xF0, 0x06, 0xD3, 0x89, 0xF8, 0x0E, 0x1E, 0x3D, 0x2E, 
	0x30, 0xD8, 0x9B, 0x60, 0x61, 0x7A, 0x3A, 0xCB, 0xC6, 0x93, 
	0x8F, 0x69, 0x56, 0x1E, 0x00, 0x06, 0xB0, 0x01, 0xC8, 0xED, 
	0x80, 0xF8, 0xDF, 0x31, 0x8D, 0x00, 0xE1, 0x58, 0x32, 0x9D, 
	0x1C, 0x1A, 0xE8, 0x95, 0x33, 0x3F, 0xDF, 0x2A, 0x02, 0x36, 
	0xD0, 0x00, 0x56, 0x81, 0xE2, 0xF3, 0x00, 0xDB, 0x5D, 0x79, 
	0xB6, 0xCC, 0x72, 0x4B, 0x97, 0x5B, 0x8F, 0xFF, 0x02, 0x78, 
	0x99, 0x27, 0xDD, 0x60, 0x50, 0xF9, 0x07, 0x00, 0x00, 0x00, 
	0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82, };

static const unsigned char data_404_html[] = {
	/* /404.html */
	0x2F, 0x34, 0x30, 0x34, 0x2E, 0x68, 0x74, 0x6D, 0x6C, 0,
	0x48, 0x54, 0x54, 0x50, 0x2F, 0x31, 0x2E, 0x30, 0x20, 0x34, 
	0x30, 0x34, 0x20, 0x46, 0x69, 0x6C, 0x65, 0x20, 0x6E, 0x6F, 
	0x74, 0x20, 0x66, 0x6F, 0x75, 0x6E, 0x64, 0x0D, 0x0A, 0x6C, 
	0x77, 0x49, 0x50, 0x2F, 0x31, 0x2E, 0x34, 0x2E, 0x31, 0x20, 
	0x28, 0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x73, 0x61, 
	0x76, 0x61, 0x6E, 0x6E, 0x61, 0x68, 0x2E, 0x6E, 0x6F, 0x6E, 
	0x67, 0x6E, 0x75, 0x2E, 0x6F, 0x72, 0x67, 0x2F, 0x70, 0x72, 
	0x6F, 0x6A, 0x65, 0x63, 0x74, 0x73, 0x2F, 0x6C, 0x77, 0x69, 
	0x70, 0x29, 0x0D, 0x0A, 0x43, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 
	0x74, 0x2D, 0x74, 0x79, 0x70, 0x65, 0x3A, 0x20, 0x74, 0x65, 
	0x78, 0x74, 0x2F, 0x68, 0x74, 0x6D, 0x6C, 0x0D, 0x0A, 0x0D, 
	0x0A, 0x3C, 0x21, 0x44, 0x4F, 0x43, 0x54, 0x59, 0x50, 0x45, 
	0x20, 0x68, 0x74, 0x6D, 0x6C, 0x20, 0x50, 0x55, 0x42, 0x4C, 
	0x49, 0x43, 0x20, 0x22, 0x2D, 0x2F, 0x2F, 0x57, 0x33, 0x43, 
	0x2F, 0x2F, 0x44, 0x54, 0x44, 0x20, 0x48, 0x54, 0x4D, 0x4C, 
	0x20, 0x33, 0x2E, 0x32, 0x20, 0x46, 0x69, 0x6E, 0x61, 0x6C, 
	0x2F, 0x2F, 0x45, 0x4E, 0x22, 0x3E, 0x0A, 0x3C, 0x68, 0x74, 
	0x6D, 0x6C, 0x3E, 0x0A, 0x3C, 0x68, 0x65, 0x61, 0x64, 0x3E, 
	0x0A, 0x20, 0x20, 0x3C, 0x6D, 0x65, 0x74, 0x61, 0x20, 0x68, 
	0x74, 0x74, 0x70, 0x2D, 0x65, 0x71, 0x75, 0x69, 0x76, 0x3D, 
	0x22, 0x43, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 0x54, 
	0x79, 0x70, 0x65, 0x22, 0x20, 0x63, 0x6F, 0x6E, 0x74, 0x65, 
	0x6E, 0x74, 0x3D, 0x22, 0x74, 0x65, 0x78, 0x74, 0x2F, 0x68, 
	0x74, 0x6D, 0x6C, 0x3B, 0x20, 0x63, 0x68, 0x61, 0x72, 0x73, 
	0x65, 0x74, 0x3D, 0x77, 0x69, 0x6E, 0x64, 0x6F, 0x77, 0x73, 
	0x2D, 0x31, 0x32, 0x35, 0x32, 0x22, 0x3E, 0x0A, 0x20, 0x20, 
	0x3C, 0x74, 0x69, 0x74, 0x6C, 0x65, 0x3E, 0x34, 0x30, 0x34, 
	0x20, 0x4E, 0x6F, 0x74, 0x20, 0x46, 0x6F, 0x75, 0x6E, 0x64, 
	0x3C, 0x2F, 0x74, 0x69, 0x74, 0x6C, 0x65, 0x3E, 0x0A, 0x3C, 
	0x2F, 0x68, 0x65, 0x61, 0x64, 0x3E, 0x0A, 0x3C, 0x62, 0x6F, 
	0x64, 0x79, 0x3E, 0x0A, 0x20, 0x20, 0x3C, 0x68, 0x31, 0x3E, 
	0x4E, 0x6F, 0x74, 0x20, 0x46, 0x6F, 0x75, 0x6E, 0x64, 0x3C, 
	0x2F, 0x68, 0x31, 0x3E, 0x0A, 0x20, 0x20, 0x3C, 0x70, 0x3E, 
	0x54, 0x68, 0x65, 0x20, 0x72, 0x65, 0x71, 0x75, 0x65, 0x73, 
	0x74, 0x65, 0x64, 0x20, 0x55, 0x52, 0x4C, 0x20, 0x77, 0x61, 
	0x73, 0x20, 0x6E, 0x6F, 0x74, 0x20, 0x66, 0x6F, 0x75, 0x6E, 
	0x64, 0x20, 0x6F, 0x6E, 0x20, 0x74, 0x68, 0x65, 0x20, 0x73, 
	0x65, 0x72, 0x76, 0x65, 0x72, 0x2E, 0x20, 0x20, 0x49, 0x66, 
	0x20, 0x79, 0x6F, 0x75, 0x20, 0x65, 0x6E, 0x74, 0x65, 0x72, 
	0x65, 0x64, 0x20, 0x74, 0x68, 0x65, 0x20, 0x55, 0x52, 0x4C, 
	0x20, 0x6D, 0x61, 0x6E, 0x75, 0x61, 0x6C, 0x6C, 0x79, 0x20, 
	0x70, 0x6C, 0x65, 0x61, 0x73, 0x65, 0x20, 0x63, 0x68, 0x65, 
	0x63, 0x6B, 0x20, 0x79, 0x6F, 0x75, 0x72, 0x20, 0x73, 0x70, 
	0x65, 0x6C, 0x6C, 0x69, 0x6E, 0x67, 0x20, 0x61, 0x6E, 0x64, 
	0x20, 0x74, 0x72, 0x79, 0x20, 0x61, 0x67, 0x61, 0x69, 0x6E, 
	0x2E, 0x3C, 0x2F, 0x70, 0x3E, 0x0A, 0x3C, 0x2F, 0x62, 0x6F, 
	0x64, 0x79, 0x3E, 0x0A, 0x3C, 0x2F, 0x68, 0x74, 0x6D, 0x6C, 
	0x3E, 0x0A, };

const struct fsdata_file file_index_html[] = {{
NULL,
data_index_html, data_index_html + 12,
sizeof(data_index_html) - 12,
1
}};

const struct fsdata_file file_img_favicon_png[] = {{
file_index_html,
data_img_favicon_png, data_img_favicon_png + 17,
sizeof(data_img_favicon_png) - 17,
1
}};

const struct fsdata_file file_404_html[] = {{
file_img_favicon_png,
data_404_html, data_404_html + 10,
sizeof(data_404_html) - 10,
1
}};

#define FS_ROOT file_404_html

#define FS_NUMFILES 3
