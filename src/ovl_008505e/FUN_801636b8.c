/* FUN_801636b8
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801636b8  body 0x801636b8..0x8016376f  size 184 B
 * body sha256 2b6f2ac3de266f5b608dc061fbd2b476f2f2792e3ce42343f871c8467a713c59
 * provider record sha256 b5b32e2167ef98f133f07da73b5a372ee34c1c96071995d4131525ee9ee6748c
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801636b8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000300;
    *(undefined1 *)(param_1 + 699) = 0x20;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x400);
  if (iVar1 != 0) {
    if (*(byte *)(param_1 + 0x1e8) == 4) {
      *(undefined4 *)(param_1 + 4) = 0x1020000;
    }
    else {
      *(uint *)(param_1 + 0x1e8) = (*(byte *)(param_1 + 0x1e8) + 1) * 0x1000000 + 0x300;
      if (*(char *)(param_1 + 0x1e8) == '\x04') {
        func_0x80077d18(4,param_1);
      }
    }
  }
  FUN_801664d8(param_1);
  FUN_80166980(param_1,4,6);
  return;
}
