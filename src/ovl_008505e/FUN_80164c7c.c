/* FUN_80164c7c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164c7c  body 0x80164c7c..0x80164d07  size 140 B
 * body sha256 c815704e7e57f8b6fff87684bd4fa2c0c299bc73fc34e0d33d3a681804e6c216
 * provider record sha256 966602f645802638188a89317235102f20e3c9ff7935a540847542a56db92c23
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164c7c(uint *param_1)

{
  int iVar1;
  
  if ((int)(param_1[0xb] + (int)*(short *)(param_1 + 0x4d)) <= (int)param_1[0xb]) {
    *param_1 = *param_1 & 0xfffffff7;
  }
  iVar1 = FUN_8016313c(param_1);
  if (iVar1 != 0) {
    *(undefined1 *)((int)param_1 + 5) = 2;
    *(undefined2 *)((int)param_1 + 6) = 0;
    *(undefined1 *)((int)param_1 + 0x2b9) = 0;
    *(undefined1 *)(param_1 + 0xb2) = 0;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    *(undefined1 *)((int)param_1 + 0x1a2) = DAT_800e12d2;
  }
  return;
}
