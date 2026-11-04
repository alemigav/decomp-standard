/* FUN_8016618c
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x8016618c  body 0x8016618c..0x801661d7  size 76 B
 * body sha256 50e7bb3a70f6075a3980cfd0d73f9c2f069469271122860f56b888a3cfce0683
 * provider record sha256 b3a83177d530b64927b2f7891f73ca913fb797c1c45413d0a67d67f3b609c93b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016618c(int param_1)

{
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  
  local_10 = *(undefined2 *)(param_1 + 0x2a);
  local_e = *(undefined2 *)(param_1 + 0x2e);
  local_c = *(undefined2 *)(param_1 + 0x32);
  func_0x80037780(0x50c00,(int)*(short *)(param_1 + 0x66),0x800e9028,&local_10);
  return;
}
