/* FUN_801636e4
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x801636e4  body 0x801636e4..0x8016375f  size 124 B
 * body sha256 d0f76ade69290ae2fecdf865e568aa053e37a2776391359977224cd4bd517226
 * provider record sha256 a75711a0ce3ae06ae6381aeb8e74fa337b802159bf141adcaeb309657c006a29
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801636e4(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_20 [8];
  
  iVar2 = *(int *)(param_1 + 0x234);
  func_0x80082200(auStack_20,0,8);
  iVar1 = func_0x80033604();
  func_0x80037780(param_2 << 0x18 | param_3 << 0x10 | param_4,(iVar1 << 0x18) >> 0x14,iVar2 + 0x38,
                  auStack_20);
  return;
}
