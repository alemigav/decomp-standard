/* FUN_8005b528
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005b528  body 0x8005b528..0x8005b563  size 60 B
 * body sha256 cb00cd6b94ff5ebe1aabb9578d4aea3e9691872fa3f0dec3722cba839ad2dcc2
 * provider record sha256 47a05b1288b74b8d328b1ee8047d559b9a258bff754b1c0c9c55e2c8d26d1fc1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int switchD_8005b520::caseD_0(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int iVar1;
  int in_t1;
  
  iVar1 = ((int)*(short *)(in_t1 + 0x10) - (int)*(short *)(in_t1 + 0x12)) / 3;
  *param_3 = (int)*(short *)(in_t1 + 0x10) + iVar1 * -2;
  *param_4 = (int)*(short *)(in_t1 + 0x12) + iVar1 * -2;
  return iVar1;
}
