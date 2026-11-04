/* FUN_8016217c
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x8016217c  body 0x8016217c..0x80162227  size 172 B
 * body sha256 eb3a9cb41f2cde8ab79aae8a5c8ec4723cd5e8ad0c8a43ee2cd53216ee329aae
 * provider record sha256 904aa64ed29921b2d607f7097d338cada23bdbc1f6960815001e2abfbb665869
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016217c(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  short sVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    if (*(char *)(param_1 + 0x2df) == '\0') {
      uVar1 = func_0x80033604();
      sVar2 = (uVar1 & 0x1f) + 0x1e;
    }
    else {
      sVar2 = 0x14;
    }
    *(short *)(param_1 + 500) = sVar2;
    *(undefined1 *)(param_1 + 0x2df) = 0;
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  sVar2 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar2 + -1;
  if (sVar2 == 1) {
    *(undefined1 *)(param_1 + 5) = 1;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  return;
}
