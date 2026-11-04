/* FUN_8016676c
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x8016676c  body 0x8016676c..0x8016684b  size 224 B
 * body sha256 a62d153b7721a2f1e247b09c2eaa0cdf322feb9251fa468e8e52ba6ba90dd9b0
 * provider record sha256 982955e12ff8bdbb089a7a151f575223969640c62255c1a00a40c7962ce1f9cd
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016676c(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x17d0 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x328,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1fa0 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x38,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x790,0);
  iVar2 = *(int *)(param_1 + 0x234);
  uVar1 = func_0x80033604();
  func_0x80037780((uVar1 & 0xff) * 4 + 0x1000 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                  iVar2 + 0x1640,0);
  return;
}
