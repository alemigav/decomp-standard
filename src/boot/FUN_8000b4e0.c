/* FUN_8000b4e0
 * image   boot (boot), base 0x80000480
 * address 0x8000b4e0  body 0x8000b4e0..0x8000b65b  size 380 B
 * body sha256 241e41ffcff519d8f514695c201d4a6e77a82c37d72718fbbe72b04317cb60ed
 * provider record sha256 4eae3e5ff15e671c44b2fa13ce6f39c65631221afb0d944065060dbcb3e97915
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8000b4e0(undefined4 param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 uVar7;
  uint uVar6;
  undefined1 auStack_50 [2];
  byte local_4e [14];
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [20];
  
  uVar6 = 0;
  uVar7 = 0;
  uVar5 = 3;
  FUN_8000cfb4();
  do {
    FUN_8000b65c(0);
    FUN_8000d1f0(1,&DAT_80016470);
    osRecvMesg(param_1,auStack_40,1);
    uVar1 = FUN_8000d1f0(0,&DAT_80016470);
    osRecvMesg(param_1,auStack_40,1);
    FUN_8000b700(auStack_3c,auStack_50);
    uVar4 = 0;
    if (DAT_80014f9c != 0) {
      puVar2 = auStack_50;
      do {
        if ((puVar2[2] & 4) == 0) {
          uVar5 = uVar5 - 1;
          break;
        }
        uVar4 = uVar4 + 1;
        puVar2 = puVar2 + 4;
      } while ((int)uVar4 < (int)(uint)DAT_80014f9c);
    }
    uVar3 = (uint)DAT_80014f9c;
    uVar5 = uVar5 & -(uint)(uVar4 != uVar3);
    if ((int)uVar5 < 1) {
      uVar5 = 0;
      if (uVar3 != 0) {
        puVar2 = auStack_50;
        do {
          if ((puVar2[3] == '\0') && ((puVar2[2] & 1) != 0)) {
            uVar6 = uVar6 | 1 << (uVar5 & 0x1f);
          }
          uVar7 = (undefined1)uVar6;
          uVar5 = uVar5 + 1;
          puVar2 = puVar2 + 4;
        } while ((int)uVar5 < (int)uVar3);
      }
      FUN_8000d020();
      *param_2 = uVar7;
      return uVar1;
    }
  } while( true );
}
