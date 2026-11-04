/* FUN_80163684
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80163684  body 0x80163684..0x80163737  size 180 B
 * body sha256 c57419c9eab1f18ad503577b2f53fa9b7756644c36147f50a67a261df4bb88c3
 * provider record sha256 7f6c72420b35f3ee37677111e48be970feeca3c12020fcb7462c026dbbefe5e6
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163684(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  ushort uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x8000700;
    *(undefined1 *)(param_1 + 6) = 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x60);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar1 != 0) {
    uVar2 = func_0x80033604();
    *(ushort *)(param_1 + 500) = uVar2 & 0xf;
    FUN_80165c68(param_1,0);
  }
  return;
}
