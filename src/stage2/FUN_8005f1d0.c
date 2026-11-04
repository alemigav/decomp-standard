/* FUN_8005f1d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005f1d0  body 0x8005f1d0..0x8005f39b  size 460 B
 * body sha256 8969cd8a58eed3a9b5e43c0efae988a520046dbc21aad5eb4ec03436a18f1ceb
 * provider record sha256 005e06d9ea54c916487859e709c455aef0aaa46b291722ff702bced88bbab6b2
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005f1d0(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x9010f00;
  }
  if (*(short *)(param_1 + 0x1a8) != 0) {
    iVar3 = *(int *)(param_1 + 0x234);
    local_20 = 0;
    local_1e = 200;
    local_1c = 0;
    if ((int)*(short *)(param_1 + 0x1a8) < *(int *)(iVar3 + 0x1078) + 300) {
      uVar2 = FUN_80033604();
      FUN_80037780((uVar2 & 0xff) * 4 + 0x60c | 0x1a000000,(int)*(short *)(param_1 + 0x66),
                   iVar3 + 0x1060,&local_20);
    }
    iVar3 = *(int *)(param_1 + 0x234);
    if ((int)*(short *)(param_1 + 0x1a8) < *(int *)(iVar3 + 0x14e0) + 300) {
      uVar2 = FUN_80033604();
      FUN_80037780((uVar2 & 0xff) * 4 + 0x60c | 0x1a000000,(int)*(short *)(param_1 + 0x66),
                   iVar3 + 0x14c8,&local_20);
    }
  }
  cVar1 = DAT_800df8c0;
  if (((param_4 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -0x40;
  }
  if (((param_4 & 2) != 0) || ('\x19' < cVar1)) {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x40;
  }
  iVar3 = FUN_80089d54(param_1,param_2,param_3,0x10100);
  if (iVar3 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xed;
    DAT_800e110c = DAT_800e110c & 0xffffff7f;
  }
  return;
}
