/* FUN_8002e848
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e848  body 0x8002e848..0x8002e86b  size 36 B
 * body sha256 ab6eabef361891cf4da9f7efd49a8acc1e680ebd53ec4f97284e21c80c9e5036
 * provider record sha256 6ca0317d1d0fc77e63e9257d1ab483cde4ff093d2c9649326c7cb693fc12e81f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002e848(int *param_1)

{
  undefined1 auStack_d0 [200];
  
  (**(code **)(*param_1 + 0xc))(param_1,auStack_d0);
  return;
}
