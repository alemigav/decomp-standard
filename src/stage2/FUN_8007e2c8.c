/* FUN_8007e2c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e2c8  body 0x8007e2c8..0x8007e30b  size 68 B
 * body sha256 6f331a03ea0c88ef4577c76522bd4f6d8c5b2569bc1e5d5de0de3ccf74053e76
 * provider record sha256 389bfbfa6d8e2a5250e4e04c72a9648e31b43b5c083a512112350c351a6a4f35
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007e2c8(uint *param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  char cVar4;
  byte local_10 [8];
  
  local_10[0] = 0;
  local_10[1] = 3;
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    param_1[0x7a] = 0x700;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
  case 1:
    FUN_80032ef4(param_1,(int)*(short *)(param_1 + 0x7d),0x50);
    iVar3 = FUN_80032f64(param_1,(int)*(short *)(param_1 + 0x7d),0x28);
    if (iVar3 == 0) {
      *(undefined1 *)((int)param_1 + 6) = 2;
      FUN_80032ef4(param_1,(int)*(short *)(param_1 + 0x7d),0x50);
    }
    FUN_80089d54(param_1,param_1[0x87],param_1[0x88],0x200);
    break;
  case 2:
    bVar1 = local_10[*(char *)((int)param_1 + 0x206)];
    *(undefined1 *)((int)param_1 + 6) = 3;
    cVar4 = *(char *)((int)param_1 + 0x1a2) + *(char *)((int)param_1 + 0x1f7);
    *(char *)((int)param_1 + 0x1a2) = cVar4;
    param_1[0x7a] = (uint)bVar1 * 0x1000000 + 0x300;
    if (*(char *)((int)param_1 + 0x206) != '\0') {
      *(char *)((int)param_1 + 0x1a2) = cVar4 + *(char *)((int)param_1 + 0x1f7) * -2;
    }
  case 3:
    FUN_800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    iVar3 = FUN_80089d54(param_1,param_1[0x8b],param_1[0x8c],0x400);
    if (iVar3 != 0) {
      *(undefined1 *)((int)param_1 + 6) = 4;
      sVar2 = *(short *)((int)param_1 + 0x1f6);
      bVar1 = local_10[*(char *)((int)param_1 + 0x206)];
      *(short *)((int)param_1 + 0x1f6) = sVar2 + -1;
      param_1[0x7a] = (bVar1 + 1) * 0x1000000;
      if (sVar2 == 1) {
        *(undefined1 *)((int)param_1 + 6) = 5;
        bVar1 = local_10[*(char *)((int)param_1 + 0x206)];
LAB_8007e4a8:
        param_1[0x7a] = (bVar1 + 2) * 0x1000000;
      }
    }
LAB_8007e520:
    FUN_80032bd8(param_1,0,0);
    break;
  case 4:
    FUN_800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    iVar3 = FUN_80089d54(param_1,param_1[0x8b],param_1[0x8c],0x200);
    if ((iVar3 == 0) ||
       (sVar2 = *(short *)((int)param_1 + 0x1f6), *(short *)((int)param_1 + 0x1f6) = sVar2 + -1,
       sVar2 != 1)) goto LAB_8007e520;
    *(undefined1 *)((int)param_1 + 6) = 5;
    bVar1 = local_10[*(char *)((int)param_1 + 0x206)];
    goto LAB_8007e4a8;
  case 5:
    FUN_800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    iVar3 = FUN_80089d54(param_1,param_1[0x8b],param_1[0x8c],0x200);
    if (iVar3 != 0) {
      *param_1 = *param_1 & 0xfffffff7;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      FUN_80083758(&DAT_800e8d00,*(undefined1 *)((int)param_1 + 0x267));
      *(undefined1 *)((int)param_1 + 5) = 6;
      *(undefined1 *)((int)param_1 + 6) = 0;
    }
    goto LAB_8007e520;
  default:
    break;
  }
  if ((*(uint *)param_1[0x85] & 0x4000) != 0) {
    FUN_80077f30(1,((*(uint *)param_1[0x85] & 0x2000) >> 0xd) * 3 + 4,param_1);
    DAT_800e112a = DAT_800e112a | 4;
  }
  return;
}
