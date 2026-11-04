/* FUN_80098c08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80098c08  body 0x80098c08..0x80098f07  size 768 B
 * body sha256 f1e5d758840ca2872bce7817ef00edbf663b81ca59b7c15003e496f5ec300620
 * provider record sha256 360b060472cf64aa5292cf0b4edf8e2062091cb7f4b29c129236c540592f9695
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80098c08(int param_1)

{
  undefined4 *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  
  FUN_8006c070(0);
  iVar7 = 2;
  iVar5 = DAT_800c52dc + 0x3f900;
  if (DAT_8012fe04 == '\0') {
    uVar3 = (uint)(byte)(&DAT_800e8ff4)[DAT_8012bfa9 * 8 + (int)(char)DAT_8012bfaa];
    sVar6 = *(short *)(&DAT_801302d2 + uVar3 * 4);
  }
  else {
    iVar4 = (int)((uint)DAT_8012bfaa << 0x18) >> 0x18;
    uVar3 = iVar4 - ((int)((uint)DAT_8012bfaa << 0x18) >> 0x1f) >> 1;
    if ((iVar4 + uVar3 * -2 & 0xff) == 0) {
      uVar3 = (uint)((byte)(&DAT_800e9013)[uVar3 & 0xff] >> 4);
    }
    else {
      uVar3 = (byte)(&DAT_800e9013)[uVar3 & 0xff] & 0xf;
    }
    sVar6 = *(short *)(&DAT_80130336 + uVar3 * 4);
    if (uVar3 - 0xb < 3) {
      uVar3 = 1;
    }
  }
  puVar1 = (undefined4 *)(DAT_800c52dc + 0x3f90c);
  FUN_800479c8(param_1 + 7U & 0xfffffff8,&DAT_8012f5bc,*(undefined2 *)(&DAT_80131080 + uVar3 * 2),1)
  ;
  do {
    iVar4 = iVar5;
    FUN_80047b04(iVar4,1);
    FUN_8004786c(iVar4,0x80,0x80,0x80);
    FUN_800478ac(iVar4,0,0);
    FUN_800479bc(iVar4,0x100,0x100 - sVar6);
    *(undefined2 *)((int)puVar1 + -2) = 0;
    *puVar1 = &DAT_8012f5bc;
    puVar1 = puVar1 + 5;
    iVar7 = iVar7 + -1;
    iVar5 = iVar4 + 0x14;
  } while (iVar7 != 0);
  iVar7 = 2;
  puVar1 = (undefined4 *)(iVar4 + 0x20);
  do {
    FUN_80047b04(iVar5,1);
    FUN_8004786c(iVar5,0x80,0x80,0x80);
    FUN_800478ac(iVar5,0,0x100 - sVar6);
    FUN_800479bc(iVar5,0x80,sVar6);
    *(undefined2 *)((int)puVar1 + -2) = 0;
    *puVar1 = &DAT_8012f5bc;
    puVar1 = puVar1 + 5;
    iVar7 = iVar7 + -1;
    iVar5 = iVar5 + 0x14;
  } while (iVar7 != 0);
  iVar7 = 2;
  sVar6 = 0x2a;
  do {
    iVar7 = iVar7 + -1;
    iVar4 = 2;
    puVar2 = (undefined2 *)(iVar5 + 10);
    do {
      FUN_80047b04(iVar5,1);
      FUN_8004786c(iVar5,0x80,0x80,0x80);
      FUN_800478ac(iVar5,sVar6,0xc);
      FUN_800479bc(iVar5,0xc,0xd);
      *(undefined **)(puVar2 + 1) = &DAT_8012f584;
      *puVar2 = 0x40;
      puVar2 = puVar2 + 10;
      iVar4 = iVar4 + -1;
      iVar5 = iVar5 + 0x14;
    } while (iVar4 != 0);
    sVar6 = sVar6 + -0xe;
  } while (iVar7 != 0);
  DAT_8012bff4 = 0x19;
  DAT_8012bff6 = 0x1e;
  return;
}
